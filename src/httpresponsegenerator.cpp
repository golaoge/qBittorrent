/*
 * Bittorrent Client using Qt4 and libtorrent.
 * Copyright (C) 2006  Ishan Arora and Christophe Dumez
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * In addition, as a special exception, the copyright holders give permission to
 * link this program with the OpenSSL project's "OpenSSL" library (or with
 * modified versions of it that use the same license as the "OpenSSL" library),
 * and distribute the linked executables. You must obey the GNU General Public
 * License in all respects for all of the code used other than "OpenSSL".  If you
 * modify file(s), you may extend this exception to your version of the file(s),
 * but you are not obligated to do so. If you do not wish to do so, delete this
 * exception statement from your version.
 *
 * Contact : chris@qbittorrent.org
 */


#include "httpresponsegenerator.h"

void HttpResponseGenerator::setMessage(const QByteArray message)
{
	HttpResponseGenerator::message = message;
	setContentLength(message.size());
}

void HttpResponseGenerator::setMessage(const QString message)
{
	setMessage(message.QString::toUtf8());
}

void HttpResponseGenerator::stripMessage()
{
	message.clear();
}

QByteArray HttpResponseGenerator::toByteArray() const
{
	return QHttpResponseHeader::toString().toUtf8() + message;
}

void HttpResponseGenerator::setContentTypeByExt(const QString ext)
{
	if(ext == "css")
	{
		setContentType("text/css");
		return;
	}
	if(ext == "gif")
	{
		setContentType("image/gif");
		return;
	}
	if(ext == "htm" || ext == "html")
	{
		setContentType("text/html");
		return;
	}
	if(ext == "js")
	{
		setContentType("text/javascript");
		return;
	}
	if(ext == "png")
	{
		setContentType("image/x-png");
		return;
	}
}
