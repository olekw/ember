/*
 Copyright (C) 2009 Erik Hjortsberg <erik.hjortsberg@gmail.com>

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "Image.h"

#include "framework/Exception.h"

#include <string.h>


namespace EmberOgre
{

namespace Terrain
{

Image::Image(unsigned int width, unsigned int channels) :
	mWidth(width), mChannels(channels), mData(new unsigned char[width * width * channels]), mDataOwned(true)
{
}

Image::Image(unsigned int width, unsigned int channels, unsigned char* data) :
	mWidth(width), mChannels(channels), mData(data), mDataOwned(false)
{
}

Image::~Image()
{
	if (mDataOwned) {
		delete[] mData;
	}
}

unsigned char* Image::getData()
{
	return mData;
}

const unsigned char* Image::getData() const
{
	return mData;
}

unsigned int Image::getChannels() const
{
	return mChannels;
}

size_t Image::getSize() const
{
	return mWidth * mWidth * mChannels;
}

unsigned int Image::getWidth() const
{
	return mWidth;
}

void Image::reset()
{
	memset(mData, '\0', getSize());
}



}

}