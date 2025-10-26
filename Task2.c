#include<stdio.h>
int main(){
    int r,c,i,j,k;                        
    printf("Enter rows & cols: ");
    scanf("%d %d",&r,&c);

    int m[r][c];                         
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            printf("m[%d][%d]: ",i+1,j+1);
            scanf("%d",&m[i][j]);
        }

    printf("\nMatrix:\n");               
    for(i=0;i<r;i++){
        for(j=0;j<c;j++) printf("%d\t",m[i][j]);
        printf("\n");
    }

    int sq=(r==c), zr=1, dg=1, id=1, sc=1, ut=1, lt=1, sy=1, ss=1;
    int det=0, idem=1, nil=1;

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(m[i][j]!=0) zr=0;

    if(sq)
    { 
        for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            if(i!=j && m[i][j]!=0) dg=0;          
            if((i==j && m[i][j]!=1)||(i!=j && m[i][j]!=0)) id=0; 
            if(i>j && m[i][j]!=0) ut=0;           
            if(i<j && m[i][j]!=0) lt=0; }

        if(dg)
        {
            int v=m[0][0];
            for(i=0;i<r;i++)
                if(m[i][i]!=v) sc=0;} 

            else sc=0;

        for(i=0;i<r;i++)
            for(j=0;j<c;j++){
            if(m[i][j]!=m[j][i]) sy=0;
            if(m[i][j]!=-m[j][i]) ss=0;}

        if(r==2)
            det=m[0][0]*m[1][1]-m[0][1]*m[1][0];
        else if(r==3)
            det=m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1]) -m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0]) +m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);

        int s1[5][5]={0},s2[5][5]={0};
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                for(k=0;k<c;k++){
                    s1[i][j]+=m[i][k]*m[k][j];
                    s2[i][j]+=m[i][k]*m[k][j];
                }

        for(i=0;i<r;i++)
            for(j=0;j<c;j++){
                if(s1[i][j]!=m[i][j]) idem=0;
                if(s2[i][j]!=0) nil=0;}
    }

    printf("\nMATRIX TYPES\n");
    if(sq) printf("Square Matrix\n"); else printf("Rectangular Matrix\n");
    if(zr) printf("Zero Matrix\n");
    if(id) printf("Identity Matrix\n");
    if(dg && !id && !sc) printf("Diagonal Matrix\n");
    if(sc) printf("Scalar Matrix\n");
    if(ut) printf("Upper Triangular Matrix\n");
    if(lt) printf("Lower Triangular Matrix\n");
    if(sy) printf("Symmetric Matrix\n");
    if(ss) printf("Skew-Symmetric Matrix\n");
    if(sq){
        if(det==0) printf("Singular");
        else printf("Non-Singular, Det=%d \n",det);
    }
    if(r==1) printf("Row Matrix\n");
    if(c==1) printf("Column Matrix\n");
    if(zr) printf("Null Matrix\n");
    if(idem) printf("Idempotent Matrix\n");
    if(nil) printf("Nilpotent Matrix\n");
    return 0;
}
