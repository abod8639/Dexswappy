#pragma once

#include <webkit2/webkit2.h>
#include "swappy.h"

G_BEGIN_DECLS

#define SWAPPY_TYPE_WEBVIEW (swappy_webview_get_type())

G_DECLARE_FINAL_TYPE(SwappyWebView, swappy_webview, SWAPPY, WEBVIEW, GtkBox)

GtkWidget *swappy_webview_new(struct swappy_state *state);

void swappy_webview_load_uri(SwappyWebView *self, const gchar *uri);

void swappy_webview_set_zoom_level(SwappyWebView *self, gdouble level);

G_END_DECLS
