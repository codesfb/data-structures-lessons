

void inverteLista(Lista *lista){
     if (listaVazia(lista))
        printf("Lista vazia!\n");
    else
    {
        No *aux = lista->fim;
        while (aux != NULL)
        {
            printf("\n%d ", aux->item);
            aux = aux->ant;
        }
        printf("\n");
    }


}