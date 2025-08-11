#include "webview.h"
#include "swappy.h"
#include "pixbuf.h"

struct _SwappyWebView {
  GtkBox parent_instance;
  WebKitWebView *web_view;
  GtkWidget *scrolled_view;
  GtkWidget *back_button;
  struct swappy_state *state;
};

G_DEFINE_TYPE(SwappyWebView, swappy_webview, GTK_TYPE_BOX)

static void swappy_webview_init(SwappyWebView *self) {
  self->web_view = WEBKIT_WEB_VIEW(webkit_web_view_new());

  self->scrolled_view = gtk_scrolled_window_new(NULL, NULL);
  gtk_container_add(GTK_CONTAINER(self->scrolled_view), GTK_WIDGET(self->web_view));

  // self->back_button = gtk_button_new_with_label("Back to editor");

  gtk_box_pack_start(GTK_BOX(self), self->back_button, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(self), self->scrolled_view, TRUE, TRUE, 0);
}

static void swappy_webview_class_init(SwappyWebViewClass *klass) {}

GtkWidget *swappy_webview_new(struct swappy_state *state) {
  SwappyWebView *self = g_object_new(SWAPPY_TYPE_WEBVIEW, NULL);
  self->state = state;
  return GTK_WIDGET(self);
}

void swappy_webview_load_uri(SwappyWebView *self, const gchar *uri) {
  webkit_web_view_load_uri(self->web_view, uri);
}

void swappy_webview_set_zoom_level(SwappyWebView *self, gdouble level) {
  webkit_web_view_set_zoom_level(self->web_view, level);
}
