// TP9
// Victor Bouvier d'Acher
// Geoffroy Rodriguez
// Arezki Meriane 

#include<iostream>
using namespace std;

template <typename Comparable>
class AVLTree
{
    public:
    AVLTree( ) { root = new TREE(); }
    AVLTree( const AVLTree & rhs ) {*this=rhs;}
    ~AVLTree( ) {makeEmpty();}

    bool isEmpty( ) const {return (root==NULL);}
    void makeEmpty( ) 
    {
        if(root != NULL)
        {
            makeEmpty(root->racine);
            root->racine = NULL;
            root->taille = 0;
            delete root;
            root = NULL;
        }
    }  
    
    void insert( const Comparable & x ) {insert(x,root);}
    // void remove( const Comparable & x ) {remove(x,root);}
    bool contains( const Comparable & x ) const {return contains(x,root);}
    
    // const AVLTree & operator=( const AVLTree & rhs )
    // {
    //     if( this != &rhs )
    //     {
    //         makeEmpty( );
    //         root = clone( rhs.root );
    //     }
    //     return *this;
    // }

	friend ostream& operator<< (ostream& out, const AVLTree& arbre)
    {
        AVL* rootTemp = arbre.root->racine;
        if(rootTemp != NULL)        // verifie si l'arbre est existant
        {
            out << "TYPE\t" << "PARENT\t" << "NOEUD\t" << "HAUTEUR\t" << endl;
            out << "____\t______\t_____\t_______" << endl;
            out << "R\t";
            arbre.imprimer(out, rootTemp);
        }else
        {
            out << "arbre inexistant\n";
        }
        return out;
    }

    private:

    // Type de noeuds utilisés dans l'arbre
    struct AVL          // arbre AVL
    {
       Comparable element;
       int hauteur;
       AVL *parent;
       AVL *left;
       AVL *right;

       AVL( const Comparable & theElement, int h, AVL *pa, AVL *lt, AVL *rt )
         : element( theElement ), hauteur( h ), parent( pa ), left( lt ), right( rt ) { }
    };    

    struct TREE         // arbre pointant sur l'arbre AVL
    {
        int taille;
        AVL *racine;
        TREE() 
        {
            taille = 0;
            racine = NULL;
        }
    };

    TREE *root;         // struct contenant la racine de l'arbre AVL

    void rotationSimpleDroit(AVL* t)
    {
        if(t == NULL)
            return;

        AVL* temp = t->left;        
        if(t->parent != NULL)       // verifie si le parent est NULL
        {
            if(t->parent->left == t)        // affecte le temp au bon endroit
                t->parent->left = temp;
            else
                t->parent->right = temp;
        }

        temp->parent = t->parent;       // change le parent

        if(temp->right != NULL)         // verifie si le droit est NULL
            temp->right->parent = t;    // change le parent dans l'arbre

        t->left = temp->right;          // affecte au gauche de l'arbre le droite du temp

        t->parent = temp;               // affecte le parent dans l'arbre
        temp->right = t;                // affecte au droit du temp l'arbre
        if(t == root->racine)           // si l'ancien arbre etait la racine affecte la nouvelle racine a root
            root->racine = temp;

    }
    void rotationSimpleGauche(AVL* t)       // meme chose que pour le droit mais a l'inverse
    {
        if(t == NULL)
            return;

        AVL* temp = t->right;
        if(t->parent != NULL)
        {
            if(t->parent->right == t)
                t->parent->right = temp;
            else
                t->parent->left = temp;
        }

        temp->parent = t->parent;

        if(temp->left != NULL)
            temp->left->parent = t;
        
        t->right = temp->left;

        t->parent = temp;
        temp->left = t;
        if(temp->parent == NULL)
            root->racine = temp;
    }

    int profondeur_arbre(AVL* a)        // calcul la profondeur d'un noeud
    {
        if (a == NULL)
            return 0;

        int prof_gauche = profondeur_arbre(a->left);
        int prof_droit = profondeur_arbre(a->right);
        return 1 + ((prof_gauche > prof_droit) ? prof_gauche : prof_droit);

    }

    void rotationDoubleDroit(AVL* t)        // fait tourner a gauche puis a droit
    {
        rotationSimpleGauche(t->left);
        rotationSimpleDroit(t);
    }

    void rotationDoubleGauche(AVL* t)       // fait tourner a droit puis a gauche
    {
        rotationSimpleDroit(t->right);
        rotationSimpleGauche(t);
    }

	void imprimer(ostream& out, AVL *t) const
	{
        if(t->parent != NULL)       // si le parent est differnet de NULL l'affiche
            out << t->parent->element << "\t";
        else                        // sinon affiche un -
            out << "-\t";
        out << t->element << "\t";  // affiche l'element
        out << "(" << t->hauteur << ")";        // affiche la hauteur
        out << endl;
		if(t->left != NULL)
        {
            out << "G\t";                       // si l'arbre va a gauche
            imprimer(out, t->left);
        }

        if(t->right != NULL)
        {
            out << "D\t";                       // si l'arbre va a droite
            imprimer(out, t->right);
        }
	}

    AVL* papa(const Comparable & x, AVL* &a)    // cherche le pere du nouveau noeud
    {
        if(a == NULL)
            return NULL;

        AVL* chercher = a;
        bool continuer = true;
        do
        {
            if(x < chercher->element && chercher->left != NULL)         // si l'element chercher est a gauche et qu'il existe un arbre a gauche va a gauche
                chercher = chercher->left;
            else if(x > chercher->element && chercher->right != NULL)   // meme chose pour la droite
                chercher = chercher->right;
            else                                                        // sinon on l'a trouve
                continuer = false;
        }while(continuer);
        return chercher;
    }

    void insert(const Comparable & x, TREE* &t)
    {
        if(contains(x, t->racine))                      // verifie si l'element n'est pas deja existant 
            return;
        AVL* pere = papa(x, t->racine);                 // cherche le pere
        AVL* nouveau = NULL;
        if(pere == NULL)                                // si il y avait pas de pere cree le pere separement
            nouveau = new AVL(x, 0, NULL, NULL, NULL);
        else
            nouveau = new AVL(x, 0, pere, NULL, NULL);
        
        if(pere == NULL)                                // si le pere est NULL affecte a la racine
            t->racine = nouveau;
        else if(x < pere->element)                      // si l'element doit allez a gauche l'affecte a gauche
            pere->left = nouveau;
        else                                            // sinon a droite
            pere->right = nouveau;
        t->taille++;                                    // aumente le nombre de noeud de l'arbre
        if(nouveau != NULL)
            debalancement(nouveau);                     // rebalance l'arbre
        hauteur(t->racine);                             // affecte la nouvelle hauteur a l'arbre
    }

    void debalancement(AVL* t)
    {
        if(t == NULL)
            return;
        int difference = profondeur_arbre(t->left) - profondeur_arbre(t->right);            // verifie la profondeur du noeud
        if(difference == 2)         // si positif == 2 debalancement a gauche de l'arbre 
        {
            if(profondeur_arbre(t->left->left) - profondeur_arbre(t->left->right) == -1)        // verifie si double rotation
                rotationDoubleDroit(t);
            else                            // sinon une seul rotation
                rotationSimpleDroit(t);
        }else if(difference == -2)          // si negatif == -2 debalancement a droite de l'arbre
        {
            if(profondeur_arbre(t->right->right) - profondeur_arbre(t->right->left) == -1)
                rotationDoubleGauche(t);
            else
                rotationSimpleGauche(t);
        }
        debalancement(t->parent);           // remonte dans l'arbre pour le rebalancer entierement
    }

    void hauteur(AVL* &t)
    {
        t->hauteur = profondeur_arbre(t)-1;     // affecte la hauteur au noeud
        if(t->left != NULL)                     // va a gauche pour reaffecter la nouvelle hauteur
        {
            hauteur(t->left);
        }

        if(t->right != NULL)                    // va a droite pour reaffecter la nouvelle hauteur
        {
            hauteur(t->right);
        }
    }



    // Cherche x dans le sous-arbre  t
    AVL* contains( const Comparable & x, AVL* t) const
    {
        while(t != NULL)
        {
            if(t->element == x)
            {
                return t;
            }
            else
            {
                if(t->element > x)
                {
                    t = t->left;
                }else
                {
                    t = t->right;
                }
            }
        }
		return NULL;
    }

    // Élimine le sous-arbre t
    void makeEmpty( AVL * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }

};
