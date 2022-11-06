# Workshop Listes Chaînées | Epitech 2022 | HUB |

Aujourd'hui on va parler des listes chaînées, notion du C qui vous sera très utile pour le Pushswap et les projets graphiques pour votre 1ère année.
Le contenu du workshop va couvrir :

Notamment :

* Création et suppression des listes chaînées
* Gestion des nodes
* Compréhension des LC vs tableaux
* Gestion des pointeurs void *, des listes chainées non typées

Pour ceux qui ont faits les workshops de listes chaînées durant la piscine, vous connaissez déjà les exercices suivants.
Voici un cours détaillé sur le fonctionnement théorique des listes chaînées:
http://carl.seleborg.free.fr/cpp/cours/chap2/linked_list.html

### Mini rappel des pointeurs

Les pointeurs (*) servent à pointer une partie de mémoire comme des données, une fonction, une structure ou n'importe quel autre type de variable.

```c
int age = 10;
int *pointeurSurAge = &age;
```

![](https://user.oc-static.com/files/5001_6000/5160.png)

Lors de l'utilisation d'un malloc, celui ci cherchera de la place dans la mémoire pour mettre vos données.
Pour aller plus en détails dans la technique, il faut savoir que les données stockées dans la ram pour votre programme sont divisés en 5 parties :

- text : votre code
- data : Les variables initialisés (globals)
- bss : Les variables non initialisés
- heap : Mémoire allouée dynamiquement 
- stack : Appel de fonction et variables locals

Le problème du cas précédent est qu'une fois l'appel à la fonction terminée, toutes les variables qu'elle a déclarées sont instantanément supprimées.
En effet, "age" étant une variable local le pointeur de celle ci n'est plus existant après la fin de la fonction.

La heap permet le contrôle complètement arbitraire de l’allocation et de la libération et c'est là que la fonction `malloc` va chercher de la place pour vos données. Par ailleurs, il n’y a aucune contrainte de taille. Lorsque le processus nécessite plus de mémoire, il en fait simplement la demande à l’OS.

Il n’y a pas de gestion de l’attribution et de l’accès aussi stricte que celle de la stack, la heap est plus flexible. Cependant, elle demande le maintient de pointeurs pour chacune des valeurs stockées. Cette gestion étant plus complexe, les performances n’en sont pas aussi bonnes.

Dans la plupart des langages plus récent la heap est gérer par ce qu'on appelle le "Garbage collection", cela permet de gérer automatiquement la mémoire allouée dans le heap (Plus d'info : https://en.wikipedia.org/wiki/Garbage_collection_(computer_science) )

### Mais alors pourquoi les listes chainées ?

Prenons l'exemple suivant, où nous avons un tableau de données qui contient un nombre définis de données

```c
struct data {
    int i;
    char *str
};

struct data *create_data(int i, char *str)
{
    struct data *data = malloc(sizeof(struct data));

    data->i = i;
    data->str = str;
    return (data);
}

void main(void)
{
    struct data **datalist = malloc(sizeof(struct data *) * 5);

    datalist[0] = create_data(5, "toto");
    datalist[1] = create_data(1, "tata");
    datalist[2] = create_data(50, "jean");
    datalist[3] = create_data(89, "pierre");
    datalist[4] = create_data(42, "kevin");
}
```

Dans le cas ici, la datalist est une liste avec un nombre de données qui doit être connu et définis à l'avance dans le programme. Le problème ici est que nous ne pouvons que modifier le contenu de chaque élément dans la liste, mais nous ne pouvons ni rajouter d'éléments au milieu de la liste, ni au début, ni à la fin.
L'intêret des listes chainées est ici, vous n'avez pas besoin de connaître à l'avance le nombre d'élement de la liste, et vous pouvez la manipuler comme vous le voulez.

Au sein de la mémoire, lorsque vous allouer la mémoire pour une liste, celle ci est allouée en un seul et unique bloc.

![](https://azeria-labs.com/wp-content/uploads/2019/03/chunk-allocated-simple-CS.png.pagespeed.ce.4F7IE_9i1S.png)

En l'occurence dans l'exemple précedent, 6 blocs au total sont alloués dans la mémoire : 

- 1 * (5 * 8) bits pour les 5 pointeurs des structure
- 5 * (16 bits) pour les structure (8 bits pour les int et 8 bits pour les pointeurs de char *)

![](https://media.geeksforgeeks.org/wp-content/uploads/Arrays-1.png)

Le problème est qu'encore une fois ce bloc écrit en mémoire, il n'est plus possible de modifier le nombre de pointeurs.

Le seul moyen est de refaire un nouveau malloc de pointeurs de structure, de copier l'ancienne liste et de free l'ancienne. Cela est possible, mais cela est très gourmand en ressources, très long en terme de code et est très difficilement justifiable dans des gros projets. 

C'est là qu'on en vient aux listes chainées !

![](https://media.geeksforgeeks.org/wp-content/uploads/Linkedlist-2.png)
![](https://www.w3resource.com/w3r_images/linked-list-single-in-c.png)

```c
struct data {
    int i;
    char *str;
};

struct node {
    void *data;
    struct node *next;
};

struct data *create_data(int i, char *str)
{
    struct data *data = malloc(sizeof(struct data));

    data->i = i;
    data->str = str;
    return (data);
}

void main(void)
{
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    
    head = malloc(sizeof(struct node));
    second = malloc(sizeof(struct node));
    third = malloc(sizeof(struct node));
    
    head->data = create_data(5, "toto");
    head->next = second;

    second->data = create_data(1, "tata");
    second->next = third;
    
    third->data = create_data(89, "pierre");
    third->next = NULL;
}
```
Ici, head fait office de réference au début de la liste chainée.
Ce code peut être largement simplifié et mis au propre et c'est là qu'on arrive aux exercices !

# 0 - Daddy

Pour bien démarrer, il vous faut un projet de départ, créez vous une structure `node` dans `main.c` qui contient vos données non typées (void *) et la prochaine node

![](http://carl.seleborg.free.fr/cpp/images/schemall.gif)

Commencer par créer votre première node à l'aide de la fonction `create_data`

/!\ Le dernier élement d'une liste chainées doit toujours finir par NULL /!\

# 1 - Tree

On va commencer à créer des nodes un peu plus dynamiquement !

Pour cette exercice, il vous faudra changer le prototype du main pour qu'il puisse recevoir des arguments.

Le but de cette exercice est de créer une liste chainée de tous les arguments passés en paramètre du programme et de remplir des structure data.

Pour cela il vous faudra : 

- Deux variables contenant pour l'une, la dernière node, pour l'autre la node actuelle tous deux mis à NULL
- Une boucle pour itérer dans les arguments
- Une nouvelle allocation de mémoire pour la node actuelle
- L'assignation du ->data pour la node actuelle
- Une vérification pour savoir si la dernière node est initialisée
- Dans le cas où c'est initialisé, on assigne le ->next de la dernière node à la node actuelle
- On change la dernière node pour la node actuelle

# 2 - Length

Une fois que vous avez réussi à initialiser votre liste chainée, on va tout simple compter le nombre d'élement dans celle ci.

Pour cela créer une fonction qui vous permettra de compter le nombre d'élements dans votre liste chainée.

Vous avez besoin de :

- Créer une variable contenant la node actuelle qu'il vous faudra pointer sur le premier élement des votre liste
- Manipuler la node actuelle à l'aide du ->next
- Dans une loop
  
Cette exercice est faisable en 4/5 lignes à l'aide d'un `for` mais peut aussi être fait avec un `while`

# 3 - Push

On fait faire une petite fonction qui vous aidera sans doute dans vos projets.

Le but de cette fonction est de rajouter un élement à la fin de votre liste chainée.

- Trouver le dernière élement de votre liste
- Créer une nouvelle node et rajouter la data et assigné next à NULL
- Ajouter au dernier élement de la liste.

# 4 - Delete

Ici, toujours un peu dans la même vibe, on va cette fois ci essayer de supprimer le dernier element de la liste.

# 5 - Print

Comme le dis le nom, ici le but est de pouvoir affiché tout les data->str de votre liste chainées en une seule fonction
