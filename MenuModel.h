/*
 * Copyright 2014 ImaginativeThinking
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MENUMODEL_H
#define MENUMODEL_H

#include <QStandardItemModel>

/**
 * @brief The MenuModel class is a model for the menu system of the UI.
 */
class MenuModel : public QStandardItemModel
{
    Q_OBJECT
    Q_PROPERTY(QString response READ getResponse NOTIFY responseChanged )
    Q_ENUMS( MenuModel_Users )
    Q_ENUMS( MenuModel_Commands )

public:
    MenuModel();
    virtual ~MenuModel();

    /**
     * @brief Defines a list of application-specific roles particually related to this view model's data model.
     *
     * Each item in the view model has a set of data elements associated with it, each with its own role.
     * Roles are used by the view to indicate to the view model which type of data it needs.  The roles
     * defined in this enum are specific to this view models data model.
     * @see <a href="http://qt-project.org/doc/qt-5.0/qtcore/qt.html#ItemDataRole-enum" style="font-weight:bold;">Qt::ItemDataRole</a>
     */
    enum MenuModel_Roles
    {
        MenuModel_Roles_User = Qt::UserRole + 1,   /**< This role is used to mark differen menu options for different users.*/
        MenuModel_Roles_Command                    /**< This role holds command this menu entry will execute. **/
    };

    /**
     * @brief The MenuModel_Users enum is a list of users in the system.
     */
    enum MenuModel_Users
    {
        MenuModel_Users_Jim,        /**< This is the Jim user. **/
        MenuModel_Users_Spock,      /**< This is the Spock user. **/
        MenuModel_Users_Leonard,    /**< This is the Leonard user. **/
        MenuModel_Users_Montgomery  /**< This is the Montgomery user. **/
    };

    /**
     * @brief The MenuModel_Commands enum lists all the commands that can be issued.
     */
    enum MenuModel_Commands
    {
        MenuModel_Commands_FullAhead,           /**< This is the Full Ahead command. **/
        MenuModel_Commands_AllStop,             /**< This is the All Stop command. **/
        MenuModel_Commands_RedAlert,            /**< This is the Red Alert command. **/
        MenuModel_Commands_Hail,                /**< This is the Communications command. **/
        MenuModel_Commands_Fire,                /**< This is the Fight command. **/
        MenuModel_Commands_Status,              /**< This is the Status Report command. **/
        MenuModel_Commands_MedicalEmergancy,    /**< This is the Medical Emergancy command. **/
        MenuModel_Commands_ScanForLifeSigns     /**< This is the Life Signs Detection command. **/
    };

    /**
     * @return A collection of the view models role names.
     * @see <a href="http://qt-project.org/doc/qt-5.0/qtcore/qabstractitemmodel.html#roleNames" style="font-weight:bold;">QAbstractItemModel</a>
     */
    virtual QHash<int,QByteArray> roleNames() const;

    /**
     * @brief initalize is used to initalize the model.
     */
    virtual void initalize();

    /**
     * @return Returns the response from the system after receiving the command.
     */
    QString getResponse();

public slots:

    /**
     * @brief executeCommand will execute the given command.
     * @param command is the command to execute.
     * @param user is the user giving the command.
     */
    void executeCommand( MenuModel_Commands command, MenuModel_Users user );

signals:

    /**
     * @brief responseChanged is emitted when the response changes.
     */
    void responseChanged();

private:

    /**
     * @brief m_response is the response to return to the user after a command has been issued.
     */
    QString m_response;
};

#endif // MENUMODEL_H
