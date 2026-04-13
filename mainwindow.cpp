#include <QFont>
#include <QVBoxLayout>
#include <QProcess>
#include <QMessageBox>
#include <QRegularExpression>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ===== UI STYLING =====
    this->resize(1200, 800); // Larger window size

    // Center all content
    QWidget* centralContainer = new QWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout(centralContainer);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(ui->Network_Interfaces);
    mainLayout->addWidget(ui->groupBox);
    mainLayout->addWidget(ui->groupBox_2);
    mainLayout->setContentsMargins(50, 30, 50, 30);
    this->setCentralWidget(centralContainer);

    // Font styling
    QFont bigFont;
    bigFont.setPointSize(14);
    ui->label_2->setFont(bigFont);
    ui->label_3->setFont(bigFont);
    ui->label->setFont(bigFont);
    ui->label_4->setFont(bigFont);
    ui->editIP->setFont(bigFont);
    ui->editSubnet->setFont(bigFont);
    ui->comboInterface->setFont(bigFont);
    ui->comboActivateDeactivate->setFont(bigFont);
     // Button styling
    // Button styling
    QFont buttonFont;
    buttonFont.setPointSize(12);
    ui->btnApply->setMinimumSize(200, 50);
    ui->btnActivate->setMinimumSize(200, 50);
    ui->btnDeactivate->setMinimumSize(200, 50);
    ui->btnApply->setFont(buttonFont);
    ui->btnActivate->setFont(buttonFont);
    ui->btnDeactivate->setFont(buttonFont);

    // Group box styling
    QFont groupBoxFont;
    groupBoxFont.setPointSize(16);
    groupBoxFont.setBold(true);
    ui->Network_Interfaces->setFont(groupBoxFont);
    ui->groupBox->setFont(groupBoxFont);
    ui->groupBox_2->setFont(groupBoxFont);

    // Spacing
    ui->verticalLayout->setSpacing(15);
    ui->horizontalLayout_3->setSpacing(20);

    // ===== FUNCTIONALITY INITIALIZATION =====
    loadNetworkInterfaces();
    refreshInterfaceInfo();

    // In MainWindow constructor, after all other UI setup:
    ui->editSubnet->setPlaceholderText("e.g., 255.255.240.0 or 20");
    ui->editSubnet->setToolTip("Enter subnet as:\n- CIDR (e.g., '20')\n- Dotted-decimal (e.g., '255.255.240.0')");
    connect(ui->btnApply, &QPushButton::clicked, this, &MainWindow::on_btnApply_clicked);
}

QString MainWindow::subnetToCidr(const QString &subnet) {
    // Try parsing as CIDR first (e.g., "24")
    bool ok;
    int cidr = subnet.toInt(&ok);
    if (ok && cidr >= 0 && cidr <= 32) {
        return QString::number(cidr);
    }

    // Parse as dotted-decimal (e.g., "255.255.255.0")
    QRegularExpression ipRegex("^(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})\\.(\\d{1,3})$");
    QRegularExpressionMatch match = ipRegex.match(subnet);
    if (match.hasMatch()) {
        quint32 mask = 0;
        for (int i = 1; i <= 4; ++i) {
            quint8 octet = match.captured(i).toUInt();
            mask = (mask << 8) | octet;
        }

        // Count the number of leading 1s in the binary mask
        int cidr = 0;
        while (mask & 0x80000000) {
            cidr++;
            mask <<= 1;
        }

        if (mask == 0 && cidr <= 32) {
            return QString::number(cidr);
        }
    }

    return ""; // Invalid
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadNetworkInterfaces()
{
    ui->comboInterface->clear();
    ui->comboActivateDeactivate->clear();

    QProcess process;
    process.start("ip", QStringList() << "-br" << "link" << "show");
    process.waitForFinished();

    QString output = process.readAllStandardOutput();
    QStringList interfaces = output.split('\n', Qt::SkipEmptyParts);

    for (const QString &line : interfaces) {
        QString interface = line.split(' ').first();
        if (interface != "lo") {  // Skip loopback interface
            ui->comboInterface->addItem(interface);
            ui->comboActivateDeactivate->addItem(interface);
        }
    }
}

void MainWindow::refreshInterfaceInfo()
{
    QProcess process;
    process.start("ip", QStringList() << "a");
    process.waitForFinished();
    ui->textInterfaces->setText(process.readAllStandardOutput());
}

void MainWindow::on_btnApply_clicked() {
    QString interface = ui->comboInterface->currentText();
    QString ip = ui->editIP->text().trimmed();
    QString subnet = ui->editSubnet->text().trimmed();

    // Validate inputs
    if (interface.isEmpty() || ip.isEmpty() || subnet.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select an interface and enter both IP and subnet.");
        return;
    }

    // Convert subnet to CIDR
    QString cidr = subnetToCidr(subnet);
    if (cidr.isEmpty()) {
        QMessageBox::warning(this, "Error", "Invalid subnet format. Use CIDR (e.g., '24') or dotted-decimal (e.g., '255.255.255.0').");
        return;
    }

    // Construct and run the command (modern way)
// Construct the sudo command
     QString program = "sudo";
     QStringList arguments;
     arguments << "ip" << "addr" << "add" << QString("%1/%2").arg(ip).arg(cidr) << "dev" << interface;

     QProcess process;
     process.start(program, arguments);  // Runs with sudo
     process.waitForFinished();

    if (process.exitCode() == 0) {
        QMessageBox::information(this, "Success", "IP address applied successfully!");
        refreshInterfaceInfo(); // Update display
    } else {
        QString error = process.readAllStandardError();
        QMessageBox::critical(this, "Error", "Failed to apply IP:\n" + error);
    }
}

void MainWindow::on_btnActivate_clicked() {
    QString interface = ui->comboActivateDeactivate->currentText();
    
    if (interface.isEmpty()) {
        QMessageBox::warning(this, "Error", "No interface selected!");
        return;
    }

    QProcess process;
    process.setProcessChannelMode(QProcess::MergedChannels); // Combine stdout/stderr
    process.start("sudo", QStringList() << "ip" << "link" << "set" << interface << "up");
    process.waitForFinished();

    if (process.exitCode() == 0) {
        QMessageBox::information(this, "Success", QString("Interface %1 activated!").arg(interface));
        refreshInterfaceInfo(); // Update UI
    } else {
        QString error = process.readAllStandardError();
        QMessageBox::critical(this, "Error", 
            QString("Failed to activate %1 (needs root?):\n%2").arg(interface, error));
    }
}

void MainWindow::on_btnDeactivate_clicked() {
    QString interface = ui->comboActivateDeactivate->currentText();
    
    if (interface.isEmpty()) {
        QMessageBox::warning(this, "Error", "No interface selected!");
        return;
    }

    QProcess process;
    process.setProcessChannelMode(QProcess::MergedChannels);
    process.start("sudo", QStringList() << "ip" << "link" << "set" << interface << "down");
    process.waitForFinished();

    if (process.exitCode() == 0) {
        QMessageBox::information(this, "Success", QString("Interface %1 deactivated!").arg(interface));
        refreshInterfaceInfo(); // Update UI
    } else {
        QString error = process.readAllStandardError();
        QMessageBox::critical(this, "Error", 
            QString("Failed to deactivate %1 (needs root?):\n%2").arg(interface, error));
    }
}
