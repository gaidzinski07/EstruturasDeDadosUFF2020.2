int search(int* vet, int num){
    int x = 0;
    int* aux = vet;
    while(aux){
        if(aux == num){
            return x;
        }
        aux++;
        x++;
    }
}