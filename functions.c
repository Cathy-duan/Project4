#include<stdlib.h>
#include<stdio.h>
#include<string.h>
/* Mengyue Duan
 * 1, I use csvfile, testc, testv to find the address. 
 * 2. I use csvfile, testc, testv to find the Coor.
 * 3. I use csvfile, testc, testv to find the Count.
 * 4. I use csvfile, testc, testv, column, min, count to find the getMin.
 * 5.I use csvfile, column, testc, testv, pMin, pCount to find the getMax.
 * 6.I use csvfile, column, testc, testv, pAvg, pCount to find the getAvg.*/
//For information on how testc and testv specify the conditions, see the project description.
// Given a CSV file, print out the addresses (street, city, state and zip) of the properties
// that satisfy all the specified conditions.
int columnnumber(char *input){
         int column1;
         if(strcmp(input,"street") ==0)  column1=0;
         if(strcmp(input,"city") ==0)  column1=1;
         if(strcmp(input,"zip") ==0)  column1=2;
         if(strcmp(input,"state") ==0)  column1=3;
         if(strcmp(input,"beds") ==0)  column1=4;
         if(strcmp(input,"baths") ==0)  column1=5;
         if(strcmp(input,"sq_ft") ==0)  column1=6;
         if(strcmp(input,"type") ==0)  column1=7;
         if(strcmp(input,"sale_date") ==0)  column1=8;
         if(strcmp(input,"price") ==0)  column1=9;
         if(strcmp(input,"latitude") ==0)  column1=10;
         if(strcmp(input,"longitude") ==0)  column1=11;
return column1;
}

int check(char *a[12],char *testv[], int c){
	int column;
	if(strcmp(testv[0],"street") ==0)  column=0;
	if(strcmp(testv[c*3],"city") ==0)  column=1;
	if(strcmp(testv[c*3],"zip") ==0)  column=2;
	if(strcmp(testv[c*3],"state") ==0)  column=3;
	if(strcmp(testv[c*3],"beds") ==0)  column=4;
	if(strcmp(testv[c*3],"baths") ==0)  column=5;
	if(strcmp(testv[c*3],"sq_ft") ==0)  column=6;
	if(strcmp(testv[c*3],"type") ==0)  column=7;
	if(strcmp(testv[c*3],"sale_date") ==0)  column=8;
	if(strcmp(testv[c*3],"price") ==0)  column=9;
	if(strcmp(testv[c*3],"latitude") ==0)  column=10;
	if(strcmp(testv[c*3],"longitude") ==0)  column=11;


	if(strcmp(testv[c*3 +1], "==")==0){
		if(strcmp(a[column],testv[c *3+2])==0) return 1;
			}
	if(strcmp(testv[c*3 +1], "!=")==0){
                 if(strcmp(a[column],testv[c *3+2])!=0) return 1;
                         }
	if(strcmp(testv[c*3 +1], "<=")==0){
                 if(atoi(a[column]) <= atoi(testv[c *3+2])) return 1;
                         }
	if(strcmp(testv[c*3 +1], ">=")==0){
                 if(atoi(a[column]) >= atoi(testv[c *3+2])) return 1;
                          }
	if(strcmp(testv[c*3 +1], "<")==0){
                 if(atoi(a[column]) < atoi(testv[c *3+2])) return 1;
                          }
	if(strcmp(testv[c*3 +1], ">")==0){
                 if(atoi(a[column]) > atoi(testv[c *3+2])) return 1;
                          }
	return 0;
}

void printAddr(char csvfile[], int testc, char *testv[]){
	FILE *fp=fopen("Sacramentorealestatetransactions.csv","r");
	int num=1;
	char *csvfil;
	while(!feof(fp)){
	
		csvfil = (char*) malloc(300);
		fgets(csvfil, 300,fp);
	if(feof(fp))
		break;
	
	char *a[12];
	for(int i=0;i<12;i++){
		a[i] = strsep(&csvfil,",");
		}
	int number=0;
	for(int i=0;i<testc;i++){
		number+=check(a,testv,i);
}
	if(number == testc){
	printf("%d:%s, %s, %s %s\n",num,a[0], a[1], a[3], a[2]);
	++num;
	}
	
	free(csvfil);
	}
fclose(fp);
}
// Given a CSV file, print out the coordinates (latitude and longitude) of the properties
// that satisfy all the specified conditions.
void printCoor(char csvfile[], int testc, char *testv[]){
FILE *fp=fopen("Sacramentorealestatetransactions.csv","r");
         int num=1;
         char *csvfil;
         while(!feof(fp)){

                 csvfil = (char*) malloc(300);
                 fgets(csvfil, 300,fp);
         if(feof(fp))
                 break;

         char *a[12];
         for(int i=0;i<12;i++){
                 a[i] = strsep(&csvfil,",");
                 }
         int number=0;
         for(int i=0;i<testc;i++){
                 number+=check(a,testv,i);
 }
         if(number == testc){
         printf("%d:(%lf, %lf)\n",num, atof(a[10]), atof(a[11]));
         ++num;
         }

         free(csvfil);
         }
 fclose(fp);
 }

// Given a CSV file, return the number of the properties that satisfy all the specified conditions.
int getCount(char csvfile[], int testc, char *testv[]){
	FILE *fp=fopen("Sacramentorealestatetransactions.csv","r");
   	int num=0;
         char *csvfil;
         while(!feof(fp)){

                 csvfil = (char*) malloc(300);
                 fgets(csvfil, 300,fp);
         if(feof(fp))
                 break;

         char *a[12];
         for(int i=0;i<12;i++){
                 a[i] = strsep(&csvfil,",");
                  }
         int number=0;
         for(int i=0;i<testc;i++){
                 number+=check(a,testv,i);
 }
         if(number == testc){
         
         num++;
         }
	
         free(csvfil);
         }
 fclose(fp);
	if(testc!=0)
 		return num;
	else if(testc ==0)
		return num-1;	
return 0;
}


// Given a CSV file, return the minimum of the specified column from the properties
// that satisfy all the specified conditions through the pMin pointer.s
// A property that has a blank value for the specified column will also be excluded from the calculation.s
// The number of the properties that are included in the computation will be returned through the pCount pointer.
void getMin(char csvfile[], char column[], int testc, char *testv[], double *pMin, int *pCount){
  FILE *fp=fopen("Sacramentorealestatetransactions.csv","r");
         int num=0;
        double y = 100000000000.0;  
	char *csvfil;
          while(!feof(fp)){

                  csvfil = (char*) malloc(300);
                  fgets(csvfil, 300,fp);
          if(feof(fp))
                  break;

          char *a[12];
          for(int i=0;i<12;i++){
                  a[i] = strsep(&csvfil,",");
                   }
          int number=0;
          for(int i=0;i<testc;i++){
                  number+=check(a,testv,i);
  }
	  int x = columnnumber(column);
	
	  
          if (number == testc && strlen(a[x])!=0 && strcmp(column,a[x]) != 0){
		num++;
         	if(atof(a[x]) < y)
			y = atof(a[x]);
		}
          free(csvfil);
          }
  fclose(fp);
 *pCount = num;
 *pMin = y;
  }

// Given a CSV file, return the maximum of the specified column from the properties
// that satisfy all the specified conditions through the pMax pointer.
// A property that has a blank value for the specified column will also be excluded from the calculation.
// The number of the properties that are included in the computation will be returned through the pCount pointer.
void getMax(char csvfile[], char column[], int testc, char *testv[], double *pMax, int *pCount){
   FILE *fp=fopen("Sacramentorealestatetransactions.csv","r");
          int num=0;
         double y = 0;
         char *csvfil;
           while(!feof(fp)){
                   csvfil = (char*) malloc(300);
                   fgets(csvfil, 300,fp);
           if(feof(fp))
                  break;

           char *a[12];
           for(int i=0;i<12;i++){
                   a[i] = strsep(&csvfil,",");
                    }
           int number=0;
           for(int i=0;i<testc;i++){
                   number+=check(a,testv,i);
   }
           int x = columnnumber(column);


           if (number == testc && strlen(a[x])!=0 && strcmp(column,a[x]) != 0){
                 num++;
                 if(atof(a[x]) > y)
                         y = atof(a[x]);
                 }
           free(csvfil);
           }
   fclose(fp);
  *pCount = num;
  *pMax = y;
   }

// Given a CSV file, return the average of the specified column from the properties
// that satisfy all the specified conditions through the pAvg pointer.
// A property that has a blank value for the specified column will also be excluded from the calculation.
// The number of the properties that are included in the computation will be returned through the pCount pointer.
void getAvg(char csvfile[], char column[], int testc, char *testv[], double *pAvg, int *pCount){
   FILE *fp=fopen("Sacramentorealestatetransactions.csv","r");
          int num=0;
         double y = 0;
         char *csvfil;
           while(!feof(fp)){

                   csvfil = (char*) malloc(300);
                   fgets(csvfil, 300,fp);
           if(feof(fp))
                   break;

           char *a[12];
           for(int i=0;i<12;i++){
                   a[i] = strsep(&csvfil,",");
                    }
           int number=0;
           for(int i=0;i<testc;i++){
                   number+=check(a,testv,i);
   }
           int x = columnnumber(column);


           if (number == testc && strlen(a[x])!=0 && strcmp(column,a[x]) != 0){
                 num++;
		
                 y+=atof(a[x]);
}
                         
                 
           free(csvfil);
           }
  fclose(fp);
  double avg = y / num;
  *pCount = num;
  *pAvg = avg;
   }



