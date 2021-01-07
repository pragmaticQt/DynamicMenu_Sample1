#include "MenuModel.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MenuModel::MenuModel() : QStandardItemModel()
{
    initalize();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
MenuModel::~MenuModel()
{
    this->clear();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QHash<int,QByteArray> MenuModel::roleNames() const
{
    // Maps the role names used in the QML to the role name enum used in the code behind.

    QHash<int, QByteArray> roles;
    roles[MenuModel_Roles_User] = "role_user";
    roles[MenuModel_Roles_Command] = "role_command";
    roles[Qt::DisplayRole] = "role_title";

    return roles;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MenuModel::initalize()
{
    auto menuItem = new QStandardItem();
    menuItem->setText( "Open a Channel" );
    menuItem->setData( MenuModel_Users_Jim, MenuModel_Roles_User );
    menuItem->setData( MenuModel_Commands_Hail, MenuModel_Roles_Command );
    this->appendRow( menuItem );

    menuItem = new QStandardItem();
    menuItem->setText( "Fire Phasers" );
    menuItem->setData( MenuModel_Users_Jim, MenuModel_Roles_User );
    menuItem->setData( MenuModel_Commands_Fire, MenuModel_Roles_Command );
    this->appendRow( menuItem );

    menuItem = new QStandardItem();
    menuItem->setText( "Red Alert" );
    menuItem->setData( MenuModel_Users_Jim, MenuModel_Roles_User );
    menuItem->setData( MenuModel_Commands_RedAlert, MenuModel_Roles_Command );
    this->appendRow( menuItem );

    menuItem = new QStandardItem();
    menuItem->setText( "Scan For Life Signes" );
    menuItem->setData( MenuModel_Users_Spock, MenuModel_Roles_User );
    menuItem->setData( MenuModel_Commands_ScanForLifeSigns, MenuModel_Roles_Command );
    this->appendRow( menuItem );

    menuItem = new QStandardItem();
    menuItem->setText( "Status Report" );
    menuItem->setData( MenuModel_Users_Spock, MenuModel_Roles_User );
    menuItem->setData( MenuModel_Commands_Status, MenuModel_Roles_Command );
    this->appendRow( menuItem );

    menuItem = new QStandardItem();
    menuItem->setText( "Status Report" );
    menuItem->setData( MenuModel_Users_Leonard, MenuModel_Roles_User );
    menuItem->setData( MenuModel_Commands_Status, MenuModel_Roles_Command );
    this->appendRow( menuItem );

    menuItem = new QStandardItem();
    menuItem->setText( "Medical Emergancy" );
    menuItem->setData( MenuModel_Users_Leonard, MenuModel_Roles_User );
    menuItem->setData( MenuModel_Commands_MedicalEmergancy, MenuModel_Roles_Command );
    this->appendRow( menuItem );

    menuItem = new QStandardItem();
    menuItem->setText( "Full Ahead" );
    menuItem->setData( MenuModel_Users_Montgomery, MenuModel_Roles_User );
    menuItem->setData( MenuModel_Commands_FullAhead, MenuModel_Roles_Command );
    this->appendRow( menuItem );

    menuItem = new QStandardItem();
    menuItem->setText( "All Stop" );
    menuItem->setData( MenuModel_Users_Montgomery, MenuModel_Roles_User );
    menuItem->setData( MenuModel_Commands_AllStop, MenuModel_Roles_Command );
    this->appendRow( menuItem );

    menuItem = new QStandardItem();
    menuItem->setText( "Status Report" );
    menuItem->setData( MenuModel_Users_Montgomery, MenuModel_Roles_User );
    menuItem->setData( MenuModel_Commands_Status, MenuModel_Roles_Command );
    this->appendRow( menuItem );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MenuModel::executeCommand( MenuModel_Commands command, MenuModel_Users user )
{
    QString commandingOfficer("");

    switch ( user )
    {
    case MenuModel_Users_Jim:
        commandingOfficer = "Captin";
        break;
    case MenuModel_Users_Spock:
        commandingOfficer = "Mr. Spock";
        break;
    case MenuModel_Users_Leonard:
        commandingOfficer = "Dr. McCoy";
        break;
    case MenuModel_Users_Montgomery:
        commandingOfficer = "Mr. Scott";
        break;
    default:
        commandingOfficer = "Unknown";
        break;
    }

    switch( command )
    {
    case MenuModel_Commands_FullAhead:
        m_response = "Full Ahead Aye " + commandingOfficer;
        break;
    case MenuModel_Commands_AllStop:
        m_response = "All Stop Aye " + commandingOfficer;
        break;
    case MenuModel_Commands_RedAlert:
        m_response = "Rasing Shields and powering Phaser banks Aye " + commandingOfficer;
        break;
    case MenuModel_Commands_Fire:
        m_response = "Firing phasers Aye " + commandingOfficer;
        break;
    case MenuModel_Commands_Hail:
        m_response = "Opening hailing frequencies Aye " + commandingOfficer;
        break;
    case MenuModel_Commands_MedicalEmergancy:
        m_response = commandingOfficer + " to the bridge, Medical Emergancy!";
        break;
    case MenuModel_Commands_ScanForLifeSigns:
        m_response = "Scaning for signes of life Aye " + commandingOfficer;
        break;
    case MenuModel_Commands_Status:
        m_response = "Here is my status report " + commandingOfficer;
        break;
    default:
        m_response = "Your command was unclear " + commandingOfficer;
        break;
    }
    emit responseChanged();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QString MenuModel::getResponse()
{
    return m_response;
}
