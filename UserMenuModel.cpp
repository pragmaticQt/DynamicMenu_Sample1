#include "UserMenuModel.h"
#include "MenuModel.h"
#include <QDebug>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
UserMenuModel::UserMenuModel() : QSortFilterProxyModel() ,
    m_userId(0)
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
UserMenuModel::~UserMenuModel()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int UserMenuModel::getUserId()
{
    return m_userId;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void UserMenuModel::setUserId( int id )
{
    // This catches and prevents binding loops
    if ( m_userId != id )
    {
        beginResetModel(); // Reset the model so that the filterAcceptsRow() method is called again

        m_userId = id;
        emit userIdChanged();

        endResetModel();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void UserMenuModel::setModel( QObject* model )
{
    auto sModel = dynamic_cast<MenuModel*>( model );
    this->setSourceModel( sModel );
    emit sourceModelChanged();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool UserMenuModel::filterAcceptsRow( int source_row, const QModelIndex& source_parent ) const
{
    bool ret( false );
    if ( this->sourceModel() != nullptr )
    {
        auto entry = this->sourceModel()->index( source_row, 0, source_parent );
        if ( entry.isValid() )
        {
            ret = ( entry.data( MenuModel::MenuModel_Roles_User ) == QVariant( m_userId ) );
        }
    }
    return ret;
}
