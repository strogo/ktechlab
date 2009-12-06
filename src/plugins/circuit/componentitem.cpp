/***************************************************************************
 *   Copyright (C) 2009 Julian Bäume <julian@svg4all.de>                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 ***************************************************************************/

#include "componentitem.h"
#include "theme.h"

#include <QVariantMap>
#include <QSvgRenderer>
#include <KDebug>

using namespace KTechLab;

ComponentItem::ComponentItem ( const QVariantMap& data, Theme *theme, QGraphicsItem* parentItem )
    : QGraphicsSvgItem ( parentItem ),
      m_renderer( new QSvgRenderer() ),
      m_theme( theme )
{
    m_renderer->load( m_theme->findFile( data.value("type").toString() ) );
    QPointF pos(data.value("x").toReal(),data.value("y").toReal());
    setPos(mapFromScene(pos));
    setSharedRenderer(m_renderer);
}

ComponentItem::~ComponentItem()
{
    delete m_renderer;
}

void ComponentItem::dataUpdated( const QString &name, const QVariantMap &data )
{
    kDebug() << "been here!";
    //updated component, so repaint
    update();
}

QString ComponentItem::imagePathForComponent( const QVariantMap &map ) const
{
/*    if ( !containment() ) {
        kWarning() << "Couldn't get the applets containment";
        return m_theme ? m_theme->imagePath( "ktechlab/components/unknown" ) : "";
    }
    QString componentTheme = containment()->config( "circuit" ).readEntry( "componentTheme", "din" );
    QString path = m_theme ? m_theme->imagePath( "ktechlab/components/"+componentTheme+"/"+map[ "type" ].toString().replace("/","_") ) : "";
    if ( path.isEmpty() ) {
        //default to unknown component
        path = m_theme ? m_theme->imagePath( "ktechlab/components/unknown" ) : "";
    }
    kDebug()<< "finding path for" << "ktechlab/components/"+componentTheme+"/"+map[ "type" ].toString().replace("/","_")
            << path;
    return path;*/
}

// vim: sw=4 sts=4 et tw=100
