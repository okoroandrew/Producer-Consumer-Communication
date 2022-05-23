void writeFile(char* path, char* text){
    /** A function that writes to an outputfile specified by the path argument*/
    FILE *f = fopen(path, "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    fprintf(f, "%s\n", text);
    fclose(f);
}
