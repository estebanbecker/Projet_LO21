

bucket RemoveHead (bucket b) {
    element* p = NULL;
    if(l != NULL){
        p = l -> next;
        if(p != NULL) {
            p->prev = NULL;
        }
        free(l);
    }
    return p;
}