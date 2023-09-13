#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 100

int parent[100];
int SIZE[100];

void make(int);
int checkcluster(int*,int,int);

// Structure to represent an edge in the graph
typedef struct {
    int src, dest;
    double weight;
} Edge;

// Structure to represent a subset for union-find algorithm
// typedef struct {
//     int parent;
//     int rank;
// } Subset;
void make(int x){
    parent[x]=x;
    SIZE[x]=1;
}
// Function to calculate the Euclidean distance between two points
double calculateDistance(double* p1, double* p2, int dimension) {
    double distance = 0.0;
    for (int i = 0; i < dimension; i++) {
        distance += pow(p1[i] - p2[i], 2);
    }
    return sqrt(distance);
}
// Function to compare edges based on their weights (for sorting)
int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return (edgeA->weight > edgeB->weight) - (edgeA->weight < edgeB->weight);
}
// Function to find the set of an element using the path compression technique
int find(int i){
    if(parent[i]==i)
        return parent[i];
    return parent[i]=find(parent[i]);
}
// Function to perform union of two sets using union by rank
void Union(int x, int y) {
    int src = find(x);
    int dest = find(y);

    if(parent[src]!=parent[dest]){
        if(SIZE[src]<SIZE[dest]){
            parent[src]=dest;
            SIZE[dest]++;
        }
        else{
            parent[dest]=src;
            SIZE[src]++;
        }
    }
}
// Function to find MST using Kruskal's algorithm
int* findClusters(double** coordinates, int numPoints, int k, int dimension) {
    int numEdges = numPoints * (numPoints - 1) / 2;
    Edge* edges = (Edge*)malloc(numEdges * sizeof(Edge));
    

    int edgeIndex = 0;
    for (int i = 0; i < numPoints; i++) {
        for (int j = i + 1; j < numPoints; j++) {
            double distance = calculateDistance(coordinates[i], coordinates[j], dimension);

            edges[edgeIndex].src = i;
            edges[edgeIndex].dest = j;
            edges[edgeIndex].weight = distance;

            edgeIndex++;
        }
    }
    // Sort the edges based on their weights
    qsort(edges, numEdges, sizeof(Edge), compareEdges);

    // we create individual points here
    for (int i = 0; i < numPoints; i++)
        make(i);
    
    int edgeCount = 0;
    int temp=numEdges;
    edgeIndex = 0;

    printf("MST:");
    while (numEdges--) {
        Edge nextEdge = edges[edgeIndex];

        if (find(edges[edgeIndex].src) != find(edges[edgeIndex].dest)) {
            Union(edges[edgeIndex].src, edges[edgeIndex].dest);
            edgeCount++;
            printf(" %d-%d,",edges[edgeIndex].src,edges[edgeIndex].dest);
        }
        edgeIndex++;
    }
    /*here we scan the sorted edge weights and assign dest vertices to src's that come first*/
    int* labels=(int*)malloc(numPoints*sizeof(int));      /*we use labels 0,1,2 to mark which clusters does points other than 1st three belongs to*/
    if(labels==NULL){
        printf("can\'t allocate space\n");
        exit(-5);
    }

    for(int i=0;i<numPoints;i++)
        labels[i]=-1;

    numEdges=temp;

    int* clusters=(int*)malloc(sizeof(int)*k);       /*contains cluster labels for a sp k*/
    if(clusters==NULL){
        printf("can\'t allocate space\n");
        exit(-6);
    }

    /*all cluster labels*/
    for(int i=0;i<k;i++)
        clusters[i]=i;

    for(int i=0;i<numEdges;i++){
        if(checkcluster(clusters,edges[i].src,k) && labels[edges[i].dest]==-1){
            if(labels[edges[i].src]==-1)
                labels[edges[i].src]=edges[i].src+1;
            labels[edges[i].dest]=labels[edges[i].src];
        }
    }

    free(edges);
    return labels;
}

int main(int argc,char** argv) {
    // Example usage
    char buffer[MAX];
    int numPoints,i=0;
    int dimension,k;
    int* labels;
    /*here we read data from file*/
    FILE *fp;
    fp=fopen(argv[1],"r");

    if(fp==NULL){
        printf("file couldn\'t be opened\n");
        exit(-1);
    }
    fgets(buffer,MAX,fp);
    numPoints=atoi(buffer);

    fgets(buffer,MAX,fp);
    dimension=atoi(buffer);

    fgets(buffer,MAX,fp);
    k=atoi(buffer);

    double *coordinates[numPoints];
    
    for(int j=0;j<numPoints;j++){
        if((coordinates[j]=(double*)malloc(sizeof(double)*dimension))==NULL)
            exit(-2);

        fgets(buffer,100,fp);
        char *token=strtok(buffer," ");
        if(token==NULL)
            break;
        for(int k=0;k<dimension;k++){
            coordinates[j][k]=atof(token);
            token=strtok(NULL," ");
        }
    }
    char outputfilename[MAX];
    FILE* fp1;
    fp1=fopen(argv[2],"w");

    if(fp1==NULL){
        printf("Couldn\'t open file\n");
        exit(-6);
    }
    labels=findClusters(coordinates, numPoints, k, dimension);

    // printf("\n");
    // for(int i=0;i<numPoints;i++)
    //     printf("%d ",labels[i]);

    for(int i=0;i<numPoints;i++){
        for(int j=0;j<dimension;j++){
            fprintf(fp1,"%f ",coordinates[i][j]);
        }
            fprintf(fp1,"%d\n",labels[i]);
    }
    fclose(fp);
    fclose(fp1);
    free(*coordinates);
    return 0;
}
int checkcluster(int* clusterlabel,int src,int k){
    for(int i=0;i<k;i++){
        if(clusterlabel[i]==src)
            return 1;
    }
    return 0;
}


