#include <glib.h>
#include <glib/gstdio.h>
#include <stdio.h>
#include <stdlib.h>

void print_key_val(gpointer key, gpointer value, gpointer u)
{
    g_printf("%s : %i\n", (char*)key, GPOINTER_TO_INT(value));
}

GHashTable* word_count_hash(gchar* text){
    //do string split to get "words"
    gchar** words = g_strsplit (text, " ", -1);
    //intialize a new hashtable
    GHashTable* counts = g_hash_table_new(g_str_hash, g_str_equal);

    //go until end of file
    int i = 0;
    while(words[i] !='\0'){
        gchar* word = words[i];
        gpointer loc;
        if(!g_hash_table_lookup_extended(counts, word, NULL, &loc)){
            //if not in hash, add and init to count of 1
            g_hash_table_insert(counts, word, GINT_TO_POINTER(1));
        } else {
            //if in hash, add 1 to count
            gpointer new_value = GINT_TO_POINTER(GPOINTER_TO_INT(loc) + 1);
            g_hash_table_replace(counts, word, new_value);
        }
        i++;
    }
    return counts;
}

int main(int argc, char** argv) {
    //file is first arg
    gchar* file = argv[1];

    // get text from file
    gchar* text;
    GError* error;

    if(!g_file_get_contents (file, &text, NULL, &error)){ //error check getting contents
        g_error("%s \n", error->message);
        return -1;
    }

    GHashTable* counts = word_count_hash(text);

    //print each value in hashtable
    g_hash_table_foreach(counts, print_key_val, NULL);
    return 0;
}
