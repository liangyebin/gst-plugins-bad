/* GStreamer
 *
 * Copyright (C) 2019 Collabora Ltd.
 *   Author: Stéphane Cerveau <scerveau@collabora.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 */
#include "gstmpdutctimingnode.h"
#include "gstmpdparser.h"

enum
{
  PROP_MPD_UTCTIMING_0,
};

G_DEFINE_TYPE (GstMPDUTCTimingNode, gst_mpd_utctiming_node, GST_TYPE_OBJECT);

/* GObject VMethods */

static void
gst_mpd_utctiming_node_finalize (GObject * object)
{
  GstMPDUTCTimingNode *self = GST_MPD_UTCTIMING_NODE (object);

  g_strfreev (self->urls);

  G_OBJECT_CLASS (gst_mpd_utctiming_node_parent_class)->finalize (object);
}

static void
gst_mpd_utctiming_node_class_init (GstMPDUTCTimingNodeClass * klass)
{
  GObjectClass *object_class = G_OBJECT_CLASS (klass);
  object_class->finalize = gst_mpd_utctiming_node_finalize;
}

static void
gst_mpd_utctiming_node_init (GstMPDUTCTimingNode * self)
{
  self->method = 0;
  self->urls = NULL;
}

GstMPDUTCTimingNode *
gst_mpd_utctiming_node_new (void)
{
  return g_object_new (GST_TYPE_MPD_UTCTIMING_NODE, NULL);
}

void
gst_mpd_utctiming_node_free (GstMPDUTCTimingNode * self)
{
  if (self)
    gst_object_unref (self);
}