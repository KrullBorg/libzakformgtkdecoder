/*
 * Copyright (C) 2015 Andrea Zagli <azagli@libero.it>
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifdef HAVE_CONFIG_H
	#include <config.h>
#endif

#include <libzakgtkdecoder/libzakgtkdecoder.h>

#include "formelementdecoder.h"

static void zak_form_gtk_form_element_decoder_class_init (ZakFormGtkFormElementDecoderClass *class);
static void zak_form_gtk_form_element_decoder_init (ZakFormGtkFormElementDecoder *zak_form_gtk_form_element_decoder);

static void zak_form_gtk_form_element_decoder_set_property (GObject *object,
                               guint property_id,
                               const GValue *value,
                               GParamSpec *pspec);
static void zak_form_gtk_form_element_decoder_get_property (GObject *object,
                               guint property_id,
                               GValue *value,
                               GParamSpec *pspec);

static void zak_form_gtk_form_element_decoder_dispose (GObject *gobject);
static void zak_form_gtk_form_element_decoder_finalize (GObject *gobject);

static gchar *zak_form_gtk_form_element_decoder_get_value (ZakFormGtkFormElementDecoder *element);
static gboolean zak_form_gtk_form_element_decoder_set_value (ZakFormGtkFormElementDecoder *element, const gchar *value);

#define ZAK_FORM_GTK_FORM_ELEMENT_DECODER_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), ZAK_FORM_GTK_TYPE_FORM_ELEMENT_DECODER, ZakFormGtkFormElementDecoderPrivate))

typedef struct _ZakFormGtkFormElementDecoderPrivate ZakFormGtkFormElementDecoderPrivate;
struct _ZakFormGtkFormElementDecoderPrivate
	{
		gpointer empty;
	};

G_DEFINE_TYPE (ZakFormGtkFormElementDecoder, zak_form_gtk_form_element_decoder, ZAK_FORM_GTK_TYPE_FORM_ELEMENT)

static void
zak_form_gtk_form_element_decoder_class_init (ZakFormGtkFormElementDecoderClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);
	ZakFormElementClass *elem_class = ZAK_FORM_ELEMENT_CLASS (klass);

	object_class->set_property = zak_form_gtk_form_element_decoder_set_property;
	object_class->get_property = zak_form_gtk_form_element_decoder_get_property;
	object_class->dispose = zak_form_gtk_form_element_decoder_dispose;
	object_class->finalize = zak_form_gtk_form_element_decoder_finalize;

	elem_class->get_value = zak_form_gtk_form_element_decoder_get_value;
	elem_class->set_value = zak_form_gtk_form_element_decoder_set_value;

	g_type_class_add_private (object_class, sizeof (ZakFormGtkFormElementDecoderPrivate));
}

static void
zak_form_gtk_form_element_decoder_init (ZakFormGtkFormElementDecoder *zak_form_gtk_form_element_decoder)
{
	ZakFormGtkFormElementDecoderPrivate *priv = ZAK_FORM_GTK_FORM_ELEMENT_DECODER_GET_PRIVATE (zak_form_gtk_form_element_decoder);

}

/**
 * zak_form_gtk_form_element_decoder_new:
 *
 * Returns: the newly created #ZakFormGtkFormElementDecoder object.
 */
ZakFormGtkFormElement
*zak_form_gtk_form_element_decoder_new ()
{
	ZakFormGtkFormElementDecoder *zak_form_gtk_form_element_decoder;

	zak_form_gtk_form_element_decoder = ZAK_FORM_GTK_FORM_ELEMENT_DECODER (g_object_new (zak_form_gtk_form_element_decoder_get_type (), NULL));

	return ZAK_FORM_GTK_FORM_ELEMENT (zak_form_gtk_form_element_decoder);
}

/**
 * zak_form_gtk_form_element_decoder_xml_parsing:
 * @element:
 * @xmlnode:
 *
 */
gboolean
zak_form_gtk_form_element_decoder_xml_parsing (ZakFormElement *element, xmlNodePtr xmlnode)
{
	ZAK_FORM_GTK_FORM_ELEMENT_CLASS (zak_form_gtk_form_element_decoder_parent_class)->xml_parsing (element, xmlnode);

	return TRUE;
}

/* PRIVATE */
static void
zak_form_gtk_form_element_decoder_set_property (GObject *object,
                   guint property_id,
                   const GValue *value,
                   GParamSpec *pspec)
{
	ZakFormGtkFormElementDecoder *zak_form_gtk_form_element_decoder = (ZakFormGtkFormElementDecoder *)object;
	ZakFormGtkFormElementDecoderPrivate *priv = ZAK_FORM_GTK_FORM_ELEMENT_DECODER_GET_PRIVATE (zak_form_gtk_form_element_decoder);

	switch (property_id)
		{
			default:
				G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
				break;
		}
}

static void
zak_form_gtk_form_element_decoder_get_property (GObject *object,
                   guint property_id,
                   GValue *value,
                   GParamSpec *pspec)
{
	ZakFormGtkFormElementDecoder *zak_form_gtk_form_element_decoder = (ZakFormGtkFormElementDecoder *)object;
	ZakFormGtkFormElementDecoderPrivate *priv = ZAK_FORM_GTK_FORM_ELEMENT_DECODER_GET_PRIVATE (zak_form_gtk_form_element_decoder);

	switch (property_id)
		{
			default:
				G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
				break;
		}
}

static void
zak_form_gtk_form_element_decoder_dispose (GObject *gobject)
{
	ZakFormGtkFormElementDecoder *zak_form_gtk_form_element_decoder = (ZakFormGtkFormElementDecoder *)gobject;
	ZakFormGtkFormElementDecoderPrivate *priv = ZAK_FORM_GTK_FORM_ELEMENT_DECODER_GET_PRIVATE (zak_form_gtk_form_element_decoder);



	GObjectClass *parent_class = g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject));
	parent_class->dispose (gobject);
}

static void
zak_form_gtk_form_element_decoder_finalize (GObject *gobject)
{
	ZakFormGtkFormElementDecoder *zak_form_gtk_form_element_decoder = (ZakFormGtkFormElementDecoder *)gobject;
	ZakFormGtkFormElementDecoderPrivate *priv = ZAK_FORM_GTK_FORM_ELEMENT_DECODER_GET_PRIVATE (zak_form_gtk_form_element_decoder);



	GObjectClass *parent_class = g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject));
	parent_class->finalize (gobject);
}

static gchar
*zak_form_gtk_form_element_decoder_get_value (ZakFormGtkFormElementDecoder *element)
{
	gchar *ret;

	GtkWidget *w;

	w = zak_form_gtk_form_element_get_widget (ZAK_FORM_GTK_FORM_ELEMENT (element));

	ret = (gchar *)zak_gtk_decoder_get_key (ZAK_GTK_DECODER (w));

	return ret;
}

static gboolean
zak_form_gtk_form_element_decoder_set_value (ZakFormGtkFormElementDecoder *element, const gchar *value)
{
	GtkWidget *w;

	w = zak_form_gtk_form_element_get_widget (ZAK_FORM_GTK_FORM_ELEMENT (element));

	zak_gtk_decoder_set_key (ZAK_GTK_DECODER (w), value);

	return TRUE;
}
