#include <gtk/gtk.h>

GtkWidget* entradaProc;

void printa_nr_processos(GtkWidget* botao, gpointer dados) {
    printf("TESTE: %s\n", gtk_entry_get_text(GTK_ENTRY(entradaProc)));
}

int main(int argc, char *argv[]) {
    GtkBuilder* builder;
    GtkWidget* window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "uitemplate.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "JanelaNrProcessos"));
    entradaProc = GTK_WIDGET(gtk_builder_get_object(builder, "entradaProc"));
    GtkWidget* bto_confirma = GTK_WIDGET(gtk_builder_get_object(builder, "confirmaNrProc"));

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(bto_confirma, "clicked", G_CALLBACK(printa_nr_processos), NULL);

    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);
    gtk_main();
    return 0;
}