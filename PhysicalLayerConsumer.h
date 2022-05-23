
char* readFile(char * path){
    /**Read a file*/
    char* buffer = 0;
    long length;
    FILE * f = fopen (path, "r");
    if (f){
        fseek (f, 0, SEEK_END);
        length = ftell (f);
        fseek (f, 0, SEEK_SET);
        buffer = (char*)malloc ((length+1)*sizeof(char));
        if (buffer){
            fread (buffer, sizeof(char), length, f);
        }
    }
    buffer[length] = '\0';
    return buffer;
}

