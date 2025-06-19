#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[100];
    float price;
} Product;

Product products[MAX_PRODUCTS]; 
int productCount = 0; 

void insertionSort(Product arr[], int n){
    // Loop through the array starting from the second element (index 1)
    for(int x = 1; x  < n; x++){
        // Store the current product to be placed at the correct position
        Product key = arr[x];

        // Initialize a variable to track the index of the previous element
        int j = x - 1;

        // Move elements of arr[0..x-1], that are **less than key.price**, one position ahead
        // This is done to create the correct position for 'key'
        while ( j >=0 && arr[j].price < key.price){
            arr[j+1] = arr[j]; // Shift the smaller product to the right
            j--;  // Move one step left in the array
        }
        // Insert the key (current product) at the correct position found
        arr[ j+1] = key;
    }
}

void selectionSort(Product arr[], int n){

    // Start a loop from the first element to the second-last element of the array.
    for(int x = 0; x < n - 1; x++)
    {
        // Assume the current index holds the minimum (or maximum) value
        int min = x;

        // Use a nested loop to scan the unsorted portion of the array (from the current index + 1 to the end).
        for (int y = x+1; y < n ; y++)
        {
            // If a smaller (or larger) element is found, update your stored index.
            if(arr[y].price < arr[min].price)
            {
                min = y;
            }
        }
        if(min != x)
        {
            Product temp = arr[x];
            arr[x] = arr[min];
            arr[min] = temp;
        }
    }
}

void bubbleSort(Product arr[], int n)
{
    for(int x = 0; x < n -1; x++)
    {
        for(int y = 0; y < n - x - 1; y++)
        {
            if(arr[y].price < arr[y+1].price)
            {
                // swap
                Product temp = arr[y];
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
        }
    }
}

// Add GTK Widgets
GtkWidget *entry_id, *entry_name, *entry_price, *text_view;

void add_product(GtkWidget *widget, gpointer data) {
    if (productCount >= MAX_PRODUCTS) return;

    const gchar *id_str = gtk_entry_get_text(GTK_ENTRY(entry_id));
    const gchar *name = gtk_entry_get_text(GTK_ENTRY(entry_name));
    const gchar *price_str = gtk_entry_get_text(GTK_ENTRY(entry_price));

    products[productCount].id = atoi(id_str);
    strcpy(products[productCount].name, name);
    products[productCount].price = atof(price_str);

    productCount++;

    gtk_entry_set_text(GTK_ENTRY(entry_id), "");
    gtk_entry_set_text(GTK_ENTRY(entry_name), "");
    gtk_entry_set_text(GTK_ENTRY(entry_price), "");
}

void display_products(GtkWidget *widget, gpointer data) {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    gtk_text_buffer_set_text(buffer, "", -1);

    char line[256];
    for (int i = 0; i < productCount; i++) {
        snprintf(line, sizeof(line), "ID: %d, Name: %s, Price: %.2f\n",
                 products[i].id, products[i].name, products[i].price);
        gtk_text_buffer_insert_at_cursor(buffer, line, -1);
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window, *grid, *button_add, *button_display;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Product Sorter");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    entry_id = gtk_entry_new();
    entry_name = gtk_entry_new();
    entry_price = gtk_entry_new();

    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_id), "Product ID");
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_name), "Product Name");
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry_price), "Price");

    button_add = gtk_button_new_with_label("Add Product");
    button_display = gtk_button_new_with_label("Display Products");

    text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);

    g_signal_connect(button_add, "clicked", G_CALLBACK(add_product), NULL);
    g_signal_connect(button_display, "clicked", G_CALLBACK(display_products), NULL);

    gtk_grid_attach(GTK_GRID(grid), entry_id, 0, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_name, 0, 1, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), entry_price, 0, 2, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), button_add, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_display, 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), text_view, 0, 4, 2, 1);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
