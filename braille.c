int isFromSecondSerie(int *array){
        int size = sizeof(array)/sizeof(int);
        
        
        if(size!=6) {
        return 0;

        }

       
       if(array[3]==1 && array[6]==0){
       
        return 1;
       
       } 
       
       else 
           
           return 0;
       
       
    }

int isFromThirdSerie(int *array){

    if(size!=6) {
     return 0;
     
    }
    
    
    if(array[3]==1 & array[6]=1) {
    
     return 1;
    }
    
    else
        return 0;

}