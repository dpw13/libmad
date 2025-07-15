/*
 * libmad - MPEG audio decoder library
 * Copyright (C) 2000-2004 Underbit Technologies, Inc.
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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * $Id: layer3.h,v 1.10 2004/01/23 09:41:32 rob Exp $
 */

# ifndef LIBMAD_LAYER3_H
# define LIBMAD_LAYER3_H

# include "stream.h"
# include "frame.h"

struct channel {
  /* from side info */
  unsigned short part2_3_length;
  unsigned short big_values;
  unsigned short global_gain;
  unsigned short scalefac_compress;

  unsigned char flags;
  unsigned char block_type;
  unsigned char table_select[3];
  unsigned char subblock_gain[3];
  unsigned char region0_count;
  unsigned char region1_count;

  /* from main_data */
  unsigned char scalefac[39];	/* scalefac_l and/or scalefac_s */
};

struct granule {
  struct channel ch[2];
};

struct sideinfo {
  unsigned int main_data_begin;
  unsigned int private_bits;

  unsigned char scfsi[2];

  struct granule gr[2];
};

int mad_layer_III(struct mad_stream *, struct mad_frame *);

# endif
