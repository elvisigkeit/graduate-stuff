typedef struct arv {
    int val;
    struct arv *esq;
    struct arv *dir;
} arv;

char novo_no(int val, arv** raiz);
void imprime_arv(arv* raiz);
char procura_no(int val, arv* raiz);
char exclui_no(int val, arv** raiz);
char rot_dir(int val, arv** raiz);
char rot_esq(int val, arv** raiz);
void limpa_arv(arv** raiz);