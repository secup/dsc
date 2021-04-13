#include <stdio.h>

#include <gcrypt.h>
#include <gtk/gtk.h>

#include "utils.c"

int main(int argc, char* argv[]) {
	
	GtkBuilder *builder;
	GObject *window;
	GError *error = NULL;
	GtkWidget *dialog, *label, *content_area;
	GtkDialogFlags flags;

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

    gcrypt_init();

	// Check if we have a key already present.

	// If not show a msgbox.

	if (1) {
		flags = GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT;
		dialog = gtk_dialog_new_with_buttons ("DSC key pair alert",
				GTK_WINDOW(window),
				flags,
				"_OK",
				GTK_RESPONSE_ACCEPT,
				"_Cancel",
				GTK_RESPONSE_REJECT,
				NULL);

		content_area = gtk_dialog_get_content_area (GTK_DIALOG (dialog));
		label = gtk_label_new ("DSC key pair not found, we will create one now!");

		gtk_container_add (GTK_CONTAINER (content_area), label);
		gtk_widget_show_all (dialog);

		int result = gtk_dialog_run (GTK_DIALOG (dialog));

		// Process result..
		switch(result) {
			case GTK_RESPONSE_ACCEPT:
				break;
			default:
				g_print("We cannot run DSC without an encryption key pair\n");
				return 1;
		}

		gtk_widget_destroy (dialog);

	}


	gtk_main();

	return 0;
}
