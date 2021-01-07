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

#ifndef USERMENUMODEL_H
#define USERMENUMODEL_H

#include <QSortFilterProxyModel>

/**
 * @brief The UserMenuModel class is used to filter the available commands so as to show only the commands available for a given user.
 */
class UserMenuModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY( QObject* model READ sourceModel WRITE setModel NOTIFY sourceModelChanged )
    Q_PROPERTY( int userId READ getUserId WRITE setUserId NOTIFY userIdChanged )

public:
    UserMenuModel();
    virtual ~UserMenuModel();

    /**
     * @return Returns the current userId;
     */
    int getUserId();

    /**
     * @brief setUserId will set the currently selected user.
     * @param id is the id of the user we want to select.
     */
    void setUserId( int id );

    /**
     * @brief setModel will set the current source model.
     * @param model is the model to use as the source for this proxy model.
     */
    void setModel( QObject* model );

    /**
     * @brief filterAcceptsRow is a predict that is run against each data entry when the souce model is added or changed.
     * If this method returns true then the data entry has satisfied the filter logic and is to be included in the proxys data set.
     * If this method returns false then the data entry is ignored (looks like it does not exist).
     * @note The base implementations of index(), parent(), rowCount(), columnCount(), data(), and setData() are all aware of the results
     * of this predict, that is they to will ignore any data entries from the source model that don't pass the filter logic.
     * @param source_row is the row number within the source model of a data entry to check.
     * @param source_parent is the parent of the data entry (used if the source model is a tree).
     * @return Returns true if the data entry passed the filter logic, false otherwise
     */
    bool filterAcceptsRow( int source_row, const QModelIndex& source_parent ) const override;

signals:

    /**
     * @brief sourceModelChanged is emitted when the current source model changes.
     */
    void sourceModelChanged();

    /**
     * @brief userIdChanged is emitted when the current user changes.
     */
    void userIdChanged();

private:

    /**
     * @brief m_userId is the id of the user who's commands we only want to show.
     */
    int m_userId;

};

#endif // USERMENUMODEL_H
