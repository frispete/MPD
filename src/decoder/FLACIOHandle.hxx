/*
 * Copyright (C) 2003-2012 The Music Player Daemon Project
 * http://www.musicpd.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef MPD_FLAC_IO_HANDLE_HXX
#define MPD_FLAC_IO_HANDLE_HXX

#include "gcc.h"
#include "input_stream.h"

#include <FLAC/callback.h>

extern const FLAC__IOCallbacks flac_io_callbacks;
extern const FLAC__IOCallbacks flac_io_callbacks_seekable;

static inline FLAC__IOHandle
ToFLACIOHandle(input_stream *is)
{
	return (FLAC__IOHandle)is;
}

static inline const FLAC__IOCallbacks &
GetFLACIOCallbacks(const input_stream *is)
{
	return is->seekable
		? flac_io_callbacks_seekable
		: flac_io_callbacks;
}

#endif
