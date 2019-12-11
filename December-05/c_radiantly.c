#include<stdio.h>
int main(int argc, char * argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Run as %s <in.csv> <out.html>", argv[0]);
        return 1;
    }

    FILE * in = fopen(argv[1], "r");
    FILE * out = fopen(argv[2], "w");

    char line[120];
    int line1 = 1;

    fprintf(out, "<html>\n\t<body>\n\t\t<table>\n");
    while(fscanf(in, "%s", line) != EOF) {

        fprintf(out, "\t\t\t<tr>");
        if(line1) fprintf(out, "<th>");
        else fprintf(out, "<td>");

        for(int i = 0; line[i] != '\0'; i++)
            if(line[i] == ',')
                if(line1) fprintf(out, "</th><th>");
                else fprintf(out, "</td><td>");
            else fprintf(out, "%c", line[i]);

        if(line1) {
            fprintf(out, "</th>");
            line1 = 0;
        } else fprintf(out, "</td>");
        fprintf(out, "</tr>\n");
    }

    fprintf(out, "\t\t</table>\n\t</body>\n</html>");

    fclose(in);
    fclose(out);

    return 0;
}
