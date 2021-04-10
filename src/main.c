#include <stdio.h>

#include <gtk/gtk.h>

int main(int argc, char* argv[]) {
	
	GtkBuilder *builder;
	GObject *window;
	GError *error = NULL;

	gtk_init (&argc, &argv);

	/* Construct a GtkBuilder instance and load our UI description */
	builder = gtk_builder_new ();
	if (gtk_builder_add_from_file (builder, "dsc_ui.glade", &error) == 0)
	{
		g_printerr ("Error loading file: %s\n", error->message);
		g_clear_error (&error);
		return 1;
	}

	/* Connect signal handlers to the constructed widgets. */
	window = gtk_builder_get_object (builder, "appWindow");
	g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);


	gtk_main();

	return 0;
}
