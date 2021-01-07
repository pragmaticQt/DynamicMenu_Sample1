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

import QtQuick 2.2
import QtQuick.Controls 2.5
import QtQml 2.3
import ca.imaginativethinking.tutorial.menu 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Dynamic Menu Sample 1")
    menuBar: applicationMenu

    MenuBar {
        id: applicationMenu

        Menu {
            title: qsTr("File")

            Action {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }
    MenuModel {
        id: menuModel
    }
    Menu {
        id: dynamicContextMenu
    }
    UserMenuModel {
        id: userMenuModel
        model: menuModel
    }

    Instantiator {
        model: userMenuModel
        onObjectAdded: dynamicContextMenu.insertItem( index, object )
        onObjectRemoved: dynamicContextMenu.removeItem( object )

        MenuItem {
            text: role_title
            onTriggered: {
                menuModel.executeCommand( role_command, role_user );
            }
        }
    }
    Text {
        id: intro
        text: qsTr("In this sample we show how to populate a menu from a model dynamically. " +
                   "To see this in action right click anywhere within the white rectangle to bring up a context menu. " +
                   "Notice a list of commands; click on one to see the response. Now via the radio buttons " +
                   "Pick a different user then try the context menu again. You will notice a different user was responded to. " +
                   "This is because when you picked a different user the model populating the menu what changed.")
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WordWrap
    }

    Row {
        id: userRow
        anchors.top: intro.bottom
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 15

        RadioButton {
            text: "Jim"
            checked: true
            onClicked: {
                if ( checked ) {
                    userMenuModel.userId = MenuModel.MenuModel_Users_Jim
                }
            }
        }
        RadioButton {
            text: "Spock"
            onClicked: {
                if ( checked ) {
                    userMenuModel.userId = MenuModel.MenuModel_Users_Spock
                }
            }
        }
        RadioButton {
            text: "Leonard"
            onClicked: {
                if ( checked ) {
                    userMenuModel.userId = MenuModel.MenuModel_Users_Leonard
                }
            }
        }
        RadioButton {
            text: "Montgomery"
            onClicked: {
                if ( checked ) {
                    userMenuModel.userId = MenuModel.MenuModel_Users_Montgomery
                }
            }
        }
    }
    Rectangle {
        anchors.top: userRow.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.right: parent.right
        height: 200

        Text {
            text: qsTr( menuModel.response )
            anchors.centerIn: parent
            width: implicitWidth > parent.width ? parent.width : implicitWidth
            font.pointSize: 18
            wrapMode: Text.WordWrap
        }
        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.RightButton
            onClicked: {
                dynamicContextMenu.popup()
            }
        }
    }
}
