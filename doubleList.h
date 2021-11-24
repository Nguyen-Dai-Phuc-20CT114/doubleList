/** ------------------------------------------------------------
 * Copyright (c) 2021 Phuc Nguyen
 *
 * $Author:             Phuc Nguyen
 * $Date:               November 12, 2021
 * $Version:            1.0.0
 *
 * File:                doubleList.h
 * Project:             Learning data structures
 * -------------------------------------------------------------
 * Brief:
 *      This is a double list with tail is linked to head, includes functions:
 *          1.  Add:        Add a brand new node
 *          2.  Insert:     Insert a existing node
 *          3.  Search:     Search a existing node
 *          4.  Delete:     Delete a existing node
 *          5.  Arrange:    Arrange list
 *          5.  Create:     Create list
**/
#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H









/* -----------------------------------------------------------------------------
/* Include libraries
/*
/* -------------------------------------------------------------------------- */
#include <iostream.h>









/* -----------------------------------------------------------------------------
/* Macro definition
/*
/* -------------------------------------------------------------------------- */

#ifndef nullptr
#define nullptr 0
#endif



// Every thing is OK
#ifndef E_OK
#define E_OK        1
#endif


/*** Errors make functions can't run ***/


// Generic errors
#ifndef E_ERR
#define E_ERR       0
#endif

// Head is invalid
#ifndef E_LIST
#define E_LIST      2
#endif

// Head is invalid
#ifndef E_HEAD
#define E_HEAD      3
#endif

// Tail is invalid
#ifndef E_TAIL
#define E_TAIL      4
#endif

// Argument <number> is invalid
#ifndef E_NUM
#define E_NUM       5
#endif

// Argument <position> is invalid
#ifndef E_POS
#define E_POS       6
#endif

// Argument <node> is invalid
#ifndef E_NODE
#define E_NODE      7
#endif


/*** Errors but functions can run ***/


// Argument <number> is too great
#ifndef W_NUM
#define W_NUM       8
#endif

// Argument <position> is too great
#ifndef W_POS
#define W_POS       9
#endif

// Current node is tail of list
#ifndef W_TAIL
#define W_TAIL      10
#endif









/* -----------------------------------------------------------------------------
/* Type definition
/*
/* -------------------------------------------------------------------------- */



typedef enum
{
    // The earlier node, the farther head
    QUEUE       =   0,

    // The ealier node, the closer head
    STACK       =   1,

} addMode_t;



// Error when using create list functions
typedef enum
{

    // Function is ok
    E_INS_OK    = E_OK,

    // List is not exist
    E_INS_LIST  = E_LIST,

    // Head of list isn't nullptr
    E_INS_HEAD  = E_HEAD,

    // Tail of list isn't nullptr
    E_INS_TAIL  = E_TAIL,

    // Number of nodes need to be created is 0
    E_INS_NUM   = E_NUM,
    
}errIns_t;



// Error when using delete functions
typedef enum
{
    // Function doesn't run (delete 0 node)
    E_DEL_NUM   = E_NUM,

    // Function is ok
    E_DEL_OK    = E_OK,

    // List is not exist
    E_DEL_LIST  = E_LIST,

    // Head of list is nullptr
    E_DEL_HEAD  = E_HEAD,

    // Tail of list is nullptr
    E_DEL_TAIL  = E_TAIL,

    // Position > number of nodes
    E_DEL_POS   = E_POS,

    // All nodes are deleted, but num input > number of nodes
    W_DEL_NUM   = W_NUM,

} errDel_t;



// Results of checking argument <position>
typedef enum
{
    // <position> is from head to tail-1
    E_MOV_OK      = E_OK,

    // <position> is a negative number
    E_MOV_ERR     = E_ERR,

    // List includes the node is not exist
    E_MOV_LIST    = E_LIST,

    // <position> is greater than tail of list
    E_MOV_OVER    = E_POS,

    // Specific node is nullptr
    E_MOV_NODE    = E_NODE,

    // <position> is at tail of list
    W_MOV_TAIL    = W_TAIL,

} errMov_t;









/* -----------------------------------------------------------------------------
/* Extern variables
/*
/* -------------------------------------------------------------------------- */









/* -----------------------------------------------------------------------------
/* Extern class
/*
/* -------------------------------------------------------------------------- */


template <class data_t>
class doubleNode_t
{

    // Variables
    private:
        doubleNode_t *ptr_next_;
        doubleNode_t *ptr_prev_;

    public:
    data_t  data_;


    // Get functions
    public:
        doubleNode_t *get_Next();
        doubleNode_t *get_Prev();


    // Set functions
    public:
        void set_Next(doubleNode_t *next);
        void set_Prev(doubleNode_t *prev);


    // Function protocols
    public:

        doubleNode_t();

};


template <class data_t>
class doubleList_t
{
    /*** Variables ***/
    private:
        doubleNode_t<data_t> *ptr_head_;
        doubleNode_t<data_t> *ptr_tail_;
    
    /*** Constructors ***/
    public:
        doubleList_t();
    
    /*** Get functions ***/
    public:
        doubleNode_t<data_t> *get_Head();
        doubleNode_t<data_t> *get_Tail();
    
    /*** Set functions ***/
    public:
        void set_Head(doubleNode_t<data_t> *head);
        void set_Tail(doubleNode_t<data_t> *tail);
    
};









/* -----------------------------------------------------------------------------
/* Extern functions template protocols
/*
/* -------------------------------------------------------------------------- */


template <class data_t>
doubleNode_t<data_t> *create_Node(doubleNode_t<data_t> *next = nullptr, doubleNode_t<data_t> *prev = nullptr, void (*setTask)(data_t &data_) = doNothing);

template <class data_t>
doubleList_t<data_t> *create_List(unsigned num = 0, void(*setTask)(data_t &data_) = doNothing);




template <class data_t>
int traverse_List(doubleList_t<data_t> *list, void (*subTask)(data_t &data_));




template <class data_t>
void arrange_List(doubleList_t<data_t> *list, bool (*conTask)(data_t data1_, data_t data2_));




template <class data_t>
doubleNode_t<data_t> *get_Node(doubleList_t<data_t> *list, unsigned pos = 0);

template <class data_t>
doubleNode_t<data_t> *get_Node(doubleList_t<data_t> *list, bool(*conTask)(data_t data_), unsigned from = 0);

template <class data_t>
doubleNode_t<data_t> *get_Tail(doubleList_t<data_t> *list);

template <class data_t>
int get_Index(doubleList_t<data_t> *list, doubleNode_t<data_t> node);

template <class data_t>
int get_Index(doubleList_t<data_t> *list, bool (*conTask)(data_t data_));




template <class data_t>
doubleNode_t<data_t> *add_Head(doubleList_t<data_t> *&list, unsigned num = 1, addMode_t addMode = STACK, void(*setTask)(data_t &data_) = doNothing);

template <class data_t>
doubleNode_t<data_t> *add_Tail(doubleList_t<data_t> *&list, unsigned num = 1, void(*setTask)(data_t &data_) = doNothing);

template <class data_t>
doubleNode_t<data_t> *add_Before(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0, addMode_t addMode = STACK, void(*setTask)(data_t &data_) = doNothing);

template <class data_t>
doubleNode_t<data_t> *add_After(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0, void(*setTask)(data_t &data_) = doNothing);




template <class data_t>
errIns_t insert_Head(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode);

template <class data_t>
errIns_t insert_Tail(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode);

template <class data_t>
errIns_t insert_Before(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode, unsigned pos = 0);

template <class data_t>
errIns_t insert_After(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode, unsigned pos = 0);




template <class data_t>
errDel_t delete_Head(doubleList_t<data_t> *&list, unsigned num = 1);

template <class data_t>
errDel_t delete_Tail(doubleList_t<data_t> *&list, unsigned num = 1);

template <class data_t>
errDel_t delete_Before(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0);

template <class data_t>
errDel_t delete_After(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0);

template <class data_t>
errDel_t delete_Node(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0);

template <class data_t>
errDel_t delete_All(doubleList_t<data_t> *&list);

template <class data_t>
errDel_t delete_List(doubleList_t<data_t> *&list);




template <class data_t>
errMov_t move_Next(doubleList_t<data_t> *&list, doubleNode_t<data_t> *&node, unsigned n);




template <class data_t>
void link_TailHead(doubleList_t<data_t> *&list);

template <class data_t>
void link_TwoNode(doubleNode_t<data_t> *node_1, doubleNode_t<data_t> *node_2);




template <class T>
void swap(T &var1, T &var2);

template <class data_t>
void doNothing(data_t &data_);



/*** Overide above functions***/


// template <class data_t>
// void traverse_List(doubleList_t<data_t> *list, data_t data, void(*subTask)(data_t &data_, data_t data));




// template <class data_t>
// doubleNode_t<data_t> *get_Node(doubleList_t<data_t> *list, unsigned pos = 0);




// template <class data_t>
// doubleNode_t<data_t> *add_Before(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0, addMode_t addMode = STACK, void(*setTask)(data_t &data_) = doNothing);

// template <class data_t>
// doubleNode_t<data_t> *add_After(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0);




// template <class data_t>
// errDel_t delete_Before(doubleList_t<data_t> *&list, unsigned num = 1);

// template <class data_t>
// errDel_t delete_After(doubleList_t<data_t> *&list, unsigned num = 1);









/* -----------------------------------------------------------------------------
/* Extern functions template definition
/*
/* -------------------------------------------------------------------------- */



/**
 * \fn                  template <class data_t> doubleNode_t<data_t> *create_Node(doubleNode_t<data_t> *next = nullptr, doubleNode_t<data_t> *prev = nullptr, void(*setTask)(data_t &data_) = doNothing)
 * \brief               Create a brand new node and set next_, prev_ for it
 * \param   next        Pointer to next node
 * \param   prev        Pointer to previous node
 * \param   setTask     Pointer to the function which set data_ for this node
 * \return              Pointer to node which is create
**/
template <class data_t>
doubleNode_t<data_t> *create_Node(doubleNode_t<data_t> *next = nullptr, doubleNode_t<data_t> *prev = nullptr, void(*setTask)(data_t &data_) = doNothing)
{
    #if true

        doubleNode_t<data_t> *node_new = new doubleNode_t<data_t>();
        node_new->set_Next(next);
        node_new->set_Prev(prev);
        (*setTask)(node_new->data_);

        return node_new;

    #endif
}


/**
 * \fn                  template <class data_t> doubleList_t<data_t> *create_List(unsigned num = 0, void(*setTask)(data_t &data_) = doNothing)
 * \brief               Create a brand new list having num nodes
 * \param   num         Number of nodes will be created
 * \param   setTask     Pointer to a function which set data_ for each node
 * \return              Errors when using create list functions
**/
template <class data_t>
doubleList_t<data_t> *create_List(unsigned num = 0, void(*setTask)(data_t &data_) = doNothing)
{
    #if true

        if(num < 0) {return nullptr;}


        doubleList_t<data_t> *list_new  = new doubleList_t();
        list_new->set_Head(nullptr);
        list_new->set_Tail(nullptr);

        for(int i = 0; i < num; ++i)
        {
            doubleNode_t<data_t> *node_new = create_Node(nullptr, nullptr, setTask);

            // If new node is the first node in the list
            if(list_new->get_Head() == nullptr)
            {
                list_new->set_Head(node_new);
                list_new->set_Tail(node_new);
            }

            // If new node is not the first node in the list
            else
            {
                // tail <-> new -> nullptr
                link_TwoNode(list_new->get_Tail(), node_new);

                // tail <-> new <-> head
                link_TwoNode(node_new, list_new->get_Head());

                // oldTail <-> tail <-> head
                list_new->set_Tail(node_new);
            }
        }

        return list_new;

    #endif
}


/* ---------------------------------------------------------------- */



/**
 * \fn                  template <class data_t> void traverse_List(doubleList_t<data_t> *list, void (*subTask)(data_t data))
 * \brief               Traverse through the nodes and do subTask att every node
 * \param   list        List wanted to traverse
 * \param   subTask     Pointer to a function doing something with argument is data_ of each node in list  
 * \return              Errors when this running function
**/
template <class data_t>
int traverse_List(doubleList_t<data_t> *list, void (*subTask)(data_t &data_))
{
    #if true

        if(list == nullptr)             {return E_LIST;}
        if(list->get_Head() == nullptr) {return E_HEAD;}
        if(list->get_Tail() == nullptr) {return E_TAIL;}


        doubleNode_t<data_t> *node_curr = list->get_Head();

        do
        {
            (*subTask)(node_curr->data_);
            node_curr = node_curr->get_Next();
        }
        while(node_curr != list->get_Head());

        return E_OK;

    #endif
}



/* ---------------------------------------------------------------- */





/**
 * \fn                  void arrange_List(doubleList_t<data_t> *list, void (*conTask)(data_t data1_, data_t data2_))
 * \brief               Arrange double list base on condition task
 * \param   list        List wanted to arrange
 * \param   conTask     Condition for swapping data of two node
 * \return              void
**/
template <class data_t>
void arrange_List(doubleList_t<data_t> *list, bool (*conTask)(data_t data1_, data_t data2_))
{
    #if true

        if(list == nullptr)             {return;}
        if(list->get_Head() == nullptr) {return;}
        if(list->get_Tail() == nullptr) {return;}
        
        if(list->get_Head() == list->get_Tail()) {return;}


        data_t data_temp;

        doubleNode_t<data_t> *node_1 = list->get_Head(); 
        doubleNode_t<data_t> *node_2 = list->get_Head();

        do
        {
            node_2 = node_1; 
            
            do
            {
                if((*conTask)(node_1->data_, node_2->data_))
                {
                    swap(node_1->data_, node_2->data_);
                }

                node_2 = node_2->get_Next();

            } 
            while(node_2 != node_1);


            node_1 = node_1->get_Next();

        } 
        while(node_1 != list->get_Head());

    #endif
}



/* ---------------------------------------------------------------- */



/**
 * \fn                  template <class data_t> doubleNode_t<data_t> *get_Node(doubleList_t<data_t> *list, unsigned pos = 0)
 * \brief               Get node by position
 * \param   list        List includes node wanted to get
 * \param   pos         Position of node wanted to get
 * \return              Pointer to node wanted to get
**/
template <class data_t>
doubleNode_t<data_t> *get_Node(doubleList_t<data_t> *list, unsigned pos = 0)
{
    #if true

        if(list == nullptr) {return nullptr;}
        if(pos < 0)         {return nullptr;}

        doubleNode_t<data_t> *node_curr = list->get_Head();

        if(move_Next(list, node_curr, pos) == E_MOV_OVER) {return nullptr;}

        return node_curr;
    
    #endif
}


/**
 * \fn                  doubleNode_t<data_t> *get_Node(doubleList_t<data_t> *list, bool(*conTask)(data_t data_), unsigned from = 0)
 * \brief               Get node by a condition task from specific position
 * \param   list        List includes node wanted to get
 * \param   conTask     Condition task
 * \param   from        Finding start from this position
 * \return              First pointer to node wanted to find
**/
template <class data_t>
doubleNode_t<data_t> *get_Node(doubleList_t<data_t> *list, bool(*conTask)(data_t data_), unsigned from = 0)
{
    #if true

        doubleNode_t<data_t> *node_curr = get_Node(list->get_Head(), from);

        bool cond = (*conTask)(node_curr->data_);
        
        while(!cond && node_curr->get_Next() != list->get_Head())
        {
            node_curr = node_curr->get_Next();
            cond = (*conTask)(node_curr->data_);
        }

        if(cond) {return node_curr;}

        return nullptr;

    #endif
}


/**
 * \fn                  template <class data_t> doubleNode_t<data_t> *get_Tail(doubleList_t<data_t> *list)
 * \brief               Get pointer to tail of double list
 * \param   list        List include wanted tail
 * \return              Pointer to tail of double list
**/
template <class data_t>
doubleNode_t<data_t> *get_Tail(doubleList_t<data_t> *list)
{
    #if true

        if(list == nullptr)             {return nullptr;}
        if(list->get_Head() == nullptr) {return nullptr;}

        doubleNode_t<data_t> *tail = list->get_Head();

        while(tail->get_Next() != list->get_Head())
        {
            tail = tail->get_Next();
        }

        return tail;
    
    #endif
}


/**
 * \fn                  template <class data_t> int get_Index(doubleList_t<data_t> *list, doubleNode_t node)
 * \brief               Get index of specific node
 * \param   list        List includes specific node
 * \param   node        Specific node
 * \return              Index of specific node
**/
template <class data_t>
int get_Index(doubleList_t<data_t> *list, doubleNode_t node)
{
    #if true

        if(list == nullptr)             {return -1;}
        if(list->get_Head() == nullptr) {return -1;}

        doubleNode_t<data_t> *node_curr = list->get_Head();

        int i = 0;
        do
        {
            if(node_curr->data == node->data){return i;}

            node_curr = node_curr->get_Next();
            ++i;
        }
        while(node_curr != list->get_Head());

        return -1;
    
    #endif
}


/**
 * \fn                  template <class data_t> int get_Index(doubleList_t<data_t> *list, bool (*conTask)(data_t data_))
 * \brief               Get index of node passed
 * \param   list        List includes node wanted to get its index
 * \param   conTask     Condition for find expected node
 * \return              Index of node
**/
template <class data_t>
int get_Index(doubleList_t<data_t> *list, bool (*conTask)(data_t data_))
{
    #if true

        if(list == nullptr)             {return -1;}
        if(list->get_Head() == nullptr) {return -1;}

        doubleNode_t<data_t> *node_curr = list->get_Head();

        int i = 0;
        do
        {
            if((*conTask)(node_curr->data_)){return i;}

            node_curr = node_curr->get_Next();
            ++i;
        }
        while(node_curr != list->get_Head());

        return -1;
    
    #endif
}



/* ---------------------------------------------------------------- */



/**
 * \fn                  template <class data_t> doubleNode_t<data_t> *add_Head(doubleList_t<data_t> *&list, unsigned num = 1, addMode_t addMode = STACK, void(*setTask)(data_t &data_) = doNothing)
 * \brief               Add new nodes at head of double list
 * \param   list        List is added new head
 * \param   num         Number of nodes will be added
 * \param   addMode     How to add new nodes: QUEUE or STACK
 * \param   setTask     Pointer to the function which set data_ of each added node
 * \return              Pointer to head of double list after inserting
**/
template <class data_t>
doubleNode_t<data_t> *add_Head(doubleList_t<data_t> *&list, unsigned num = 1, addMode_t addMode = STACK, void(*setTask)(data_t &data_) = doNothing)
{
    #if true

        if(list == nullptr)             {return nullptr;}
        if(list->get_Head() == nullptr) {return nullptr;}
        if(list->get_Tail() == nullptr) {return nullptr;}
        if(num <= 0)                    {return nullptr;}

        if(addMode == STACK)
        {
            doubleList_t<data_t> *list_new = create_List(num, setTask);

            // tail <-> newList -> nullptr
            link_TwoNode(list->get_Tail(), list_new->get_Head());

            // tail <-> newList <-> head
            link_TwoNode(list_new->get_Tail(), list->get_Head());

            // tail <-> newHead
            list->set_Head(list_new->get_Head());

            delete list_new;
        }

        else if(addMode == QUEUE)
        {
            for(int i = 1; i <= num; ++i)
            {
                // tail <- new -> head
                doubleNode_t<data_t> *node_new = create_Node(list->get_Head(), list->get_Tail(), setTask);

                // tail <-> new -> head
                list->get_Tail->set_Next(node_new);

                // tail <-> new <-> head
                list->get_Head()->set_Prev(node_new);

                // tail <-> head <-> old
                list->set_Head(node_new);
            }
        }

        return list->get_Head();

    #endif
}


/**
 * \fn                  template <class data_t> doubleNode_t<data_t> *add_Tail(doubleList_t<data_t> *&list, unsigned num = 1, void(*setTask)(data_t &data_) = doNothing)
 * \brief               Add new nodes at tail of double list
 * \param   list        List is added new tail
 * \param   num         Number of nodes will be added
 * \param   setTask     Pointer to the function which set data_ of each added node
 * \return              Pointer to tail of double list after inserting
**/
template <class data_t>
doubleNode_t<data_t> *add_Tail(doubleList_t<data_t> *&list, unsigned num = 1, void(*setTask)(data_t &data_) = doNothing)
{
    #if true

        if(list == nullptr)           {return nullptr;}
        if(list->get_Head == nullptr) {return nullptr;}
        if(list->get_Tail == nullptr) {return nullptr;}
        if(num <= 0)                  {return nullptr;}  

        for(int i = 0; i < num; ++i)
        {
            // tail <- new -> head
            doubleNode_t<data_t> *node_new = create_Node(list->get_Head(), list->get_Tail(), setTask);

            // tail <-> new -> head
            list->get_Tail()->set_Next(node_new);

            // tail <-> new <-> head
            list->get_Head()->set_Prev(node_new);

            // oldTail <-> tail <-> head
            list->set_Tail(node_new);
        }

        return list->get_Tail();

    #endif
}


/**
 * \fn                  template <class data_t> doubleNode_t<data_t> *add_Before(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0, addMode_t addMode = STACK, void(*setTask)(data_t &data_) = doNothing)
 * \brief               Add new nodes before a specified position
 * \param   list        List is added new nodes
 * \param   num         Number of nodes will be added
 * \param   pos         Position for add nodes
 * \param   addMode     How to add new nodes: QUEUE or STACK
 * \param   setTask     Pointer to the function which set data_ of each added node
 * \return              Pointer to final node added
**/
template <class data_t>
doubleNode_t<data_t> *add_Before(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0, addMode_t addMode = STACK, void(*setTask)(data_t &data_) = doNothing)
{
    #if true

        if(list == nullptr)             {return nullptr;}
        if(list->get_Head() == nullptr) {return nullptr;}
        if(list->get_Tail() == nullptr) {return nullptr;}
        if(num <= 0)                    {return nullptr;}
        if(pos <  0)                    {return nullptr;}


        if(pos == 0)
        {
            return add_Head(list, num, addMode, setTask);
        }

        else
        {
            /*** Get specific node ***/
            doubleNode_t<data_t> *node_spec = list->get_Head();

            if(move_Next(list, node_spec, pos) == E_MOV_OVER) {return nullptr;}


            /*** Get node before specific node ***/
            doubleNode_t<data_t> *node_befo = node_spec->get_Prev();


            /*** Create a new list which includes new nodes ***/
            doubleList_t<data_t> *list_new = create_List()


            return node_befo->get_Next();
        }
    
    #endif
}


/**
 * \fn                  template <class data_t> doubleNode_t<data_t> *add_After(doubleList_t<data_t> *&list, unsigned num=1, unsigned pos=0)
 * \brief               Add new nodes after a specific position
 * \param   list        List is added new nodes
 * \param   num         Number of nodes will be added
 * \param   pos         Position for add nodes
 * \return              Pointer to final node added
**/
template <class data_t>
doubleNode_t<data_t> *add_After(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0, void(*setTask)(data_t &data_) = doNothing)
{
    #if true

        if(list->get_Head() == nullptr) {return nullptr;}
        if(list->get_Tail() == nullptr) {return nullptr;}
        if(num <= 0)                    {return nullptr;}
        if(pos <  0)                    {return nullptr;}

    
    // if(pos == 0)
    // {
    //     if(list->get_Head() == tail)
    //     {
    //         return add_Tail(tail, num);
    //     }

    //     else
    //     {
    //         doubleNode_t<data_t> *node_head = nullptr;
    //         doubleNode_t<data_t> *doubleNode_tail = create_List(node_head, num);

    //         // sub-list tail is linked to 1th node of old list
    //         list_new->get_Tail()->set_Next(head->get_Next());

    //         // First node of old list is linked to sub-list head
    //         head->set_Next(node_head);

    //         return doubleNode_tail;

    //     }
    // }

    // pos > 0
    // else
    // {
        doubleNode_t<data_t> *node_curr = list->get_Head();

        int i = 0;
        while(i < pos && node_curr->get_Next() != list->get_Head())
        {
            node_curr = node_curr->get_Next();
            ++i;
        }

        if(node_curr->get_Next() == list->get_Head())
        {
            // pos is tail of double list
            if(i == pos)
            {
                return add_Tail(tail, num);
            }

            // pos > number of nodes
            else
            {
                return nullptr;
            }
        }

        else
        {
            doubleNode_t<data_t> *node_next = node_curr->get_Next();

            doubleNode_t<data_t> *temp = add_Tail(node_curr, num);

            temp->set_Next(node_next);

            return temp;
        }
    // }

    #endif
}


/**
 * \fn                  template <class data_t> doubleNode_t<data_t> *add_After(doubleNode_t<data_t> *&node, unsigned num=1, unsigned pos=0)
 * \brief               Add new nodes after a specific position
 * \param   node        Specific node
 * \param   num         Number of nodes will be added
 * \param   pos         Position for add nodes
 * \return              Pointer to final node added
**/
template <class data_t>
doubleNode_t<data_t> *add_After(doubleNode_t<data_t> *&node, unsigned num = 1, unsigned pos = 0)
{
    #if true

        if(node == nullptr) {return nullptr;}
        if(num <= 0)        {return nullptr;}
        if(pos <  0)        {return nullptr;}

        
        /*** Get specific node ***/
        doubleNode_t<data_t> *node_curr = node;
        errMov_t errMove = move_Next(list, node_curr, pos);



        /*** pos > number of nodes ***/
        if(errMove == E_MOV_OVER) {return nullptr;}


        /*** pos <= number of node ***/

        // curr   the news
        doubleList_t<data_t> *list_new;
        create_List(list_new, num);

        // curr   the news   next
        doubleNode_t<data_t> *node_next = node_curr->get_Next();

        // curr <-> the news   next
        link_TwoNode(node_curr, list_new->get_Head());

        // curr <-> the news <-> next
        link_TwoNode(list_new->get_Tail(), node_next);
        

    #endif
}



/* ---------------------------------------------------------------- */



/**
 * \fn                  template <class data_t> errIns_t insert_Head(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode)
 * \brief               Insert an existing node before the head of list
 * \param   list           List includes
 * \param   newNode     Node is inserted
 * \return              Error when using insert functions
**/
template <class data_t>
errIns_t insert_Head(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode)
{
    #if true

        if(head    == nullptr)  {return E_INS_HEAD;     }
        if(newNode == nullptr)  {return E_INS_NEW_NODE; }

        doubleNode_t<data_t> *node_new = new doubleNode_t<data_t>();
        node_new = newNode;

        node_new->set_Next(list->get_Head());
        head = node_new;

        return E_INS_OK;

    #endif
}


/**
 * \fn                  template <class data_t> errIns_t insert_Tail(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode)
 * \brief               Insert an existing node after the tail of list
 * \param   list        List includes
 * \param   newNode     Node is inserted
 * \return              Error when using insert functions
**/
template <class data_t>
errIns_t insert_Tail(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode)
{
    #if true

        if(tail    == nullptr)  {return E_INS_TAIL;     }
        if(newNode == nullptr)  {return E_INS_NEW_NODE; }

        doubleNode_t<data_t> *node_new = new doubleNode_t<data_t>();
        node_new = newNode;

        node_new->set_Next(nullptr);
        tail    ->set_Next(newNode);
        tail    = node_new;

        return E_INS_OK;

    #endif
}


/**
 * \fn                  template <class data_t> errIns_t insert_Before(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode, unsigned pos = 0)
 * \brief               Insert an existing node before specific node in the list
 * \param   list           List includes
 * \param   newNode     Node is inserted
 * \param   pos         newNode is inserted before this position
 * \return              Error when using insert functions
**/
template <class data_t>
errIns_t insert_Before(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode, unsigned pos = 0)
{
    #if true

        if(head    == nullptr)  {return E_INS_HEAD;     }
        if(newNode == nullptr)  {return E_INS_NEW_NODE; }

        // pos = head
        if(pos == 0) {return insert_Head(head, newNode);}


        /*** pos > head ***/


        doubleNode_t<data_t> *node_curr = list->get_Head();
        doubleNode_t<data_t> *node_befo = head;

        int i = 0;
        while(i < pos && node_curr->get_Next() != list->get_Head())
        {
            node_befo = node_curr;
            node_curr = node_curr->get_Next();
            ++i;
        }

        // pos > number of nodes
        if(node_curr->get_Next() == list->get_Head() && i < pos)
        {
            return E_INS_POS;
        }

        doubleNode_t<data_t> *node_new = new doubleNode_t<data_t>();
        node_new = newNode;

        node_befo->set_Next(node_new);
        node_new->set_Next(node_curr);

        return E_INS_OK;

    #endif
}


/**
 * \fn                  template <class data_t> errIns_t insert_After(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode, unsigned pos = 0)
 * \brief               Insert an existing node after specific node in the list
 * \param   list           List includes
 * \param   list        List includes
 * \param   newNode     Node is inserted
 * \param   pos         newNode is inserted after this position
 * \return              Error when using insert functions
**/
template <class data_t>
errIns_t insert_After(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode, unsigned pos = 0)
{
    #if true

        if(head    == nullptr)  {return E_INS_HEAD;     }
        if(tail    == nullptr)  {return E_INS_TAIL;     }
        if(newNode == nullptr)  {return E_INS_NEW_NODE; }

        // There is 1 node
        if(head == tail) {return insert_Tail(tail, newNode);}



        /*** There are many nodes ***/


        doubleNode_t<data_t> *node_curr = list->get_Head();

        int i = 0;
        while(i < pos && node_curr->get_Next() != list->get_Head())
        {
            node_curr = node_curr->get_Next();
            ++i;
        }

        // pos > number of nodes
        if(node_curr->get_Next() == list->get_Head() && i < pos)
        {
            // pos is tail of double list
            if(i == pos){return insert_Tail(tail, newNode);}

            // pos > number of nodes
            if(i < pos){return E_INS_POS;}
            
        }

        // pos < number of nodes
        else
        {
            // node_curr -> node_next
            doubleNode_t<data_t> *node_next = node_curr->get_Next();

            //        node_new
            // node_curr -> node_next
            doubleNode_t<data_t> *node_new = new doubleNode_t<data_t>();
            node_new = newNode;

            // node_curr -> node new -> node_next
            node_curr->set_Next(node_new);
            node_new ->set_Next(node_next);

        }

        return E_INS_OK;

    #endif
}



/* ---------------------------------------------------------------- */



/**
 * \fn                  template <class data_t> errDel_t delete_Head(doubleList_t<data_t> *&list, unsigned num = 1)
 * \brief               Delete first node n times
 * \param   list           List includes
 * \param   list        List includes
 * \param   num         Number of times that first node is deleted
 * \return              Error when using delete functions
**/
template <class data_t>
errDel_t delete_Head(doubleList_t<data_t> *&list, unsigned num = 1)
{
#if true

    if(num  == 0)       {return E_DEL_NUM;  }
    if(list->get_Head() == nullptr) {return E_INS_HEAD; }
    if(tail == nullptr) {return E_INS_TAIL; }
    
    // There is 1 node
    if(head == tail)
    {
        doubleNode_t<data_t> *node_curr = list->get_Head();
        delete node_curr;

        head = tail = nullptr;

        if(num != 1) {return W_DEL_NUM; }
    }

    else
    {
        doubleNode_t<data_t> *node_befo = head;
        doubleNode_t<data_t> *node_curr = list->get_Head();

        int i = 0;
        while(node_curr != nullptr && i < num)
        {
            node_befo = node_curr;
            node_curr = node_curr->get_Next();
            delete node_befo;
            ++i;
        }
                    
        head = node_curr;

        // Now list is empty
        if(node_curr == nullptr)
        {
            tail = nullptr;
            if(i < num -1) {return W_DEL_NUM;}
        }
    }

    return E_INS_OK;
            
#endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_Tail(doubleList_t<data_t> *&list, unsigned num = 1)
 * \brief               Delete last node n times
 * \param   list           List includes
 * \param   list        List includes
 * \param   num         Number of times that last node is deleted
 * \return              void
**/
template <class data_t>
errDel_t delete_Tail(doubleList_t<data_t> *&list, unsigned num = 1)
{
    #if true

        if(num  == 0)       {return E_DEL_NUM;  }
        if(list->get_Head() == nullptr) {return E_INS_HEAD; }
        if(tail == nullptr) {return E_INS_TAIL; }
        
        if(num == 1)
        {
            // There is 1 node
            if(head == tail)
            {
                delete head;
                head = tail = nullptr;
            }

            else
            {
                doubleNode_t<data_t> *node_befo = head;
                doubleNode_t<data_t> *node_curr = list->get_Head();

                while(node_curr->get_Next() != list->get_Head())
                {
                    node_befo = node_curr;
                    node_curr = node_curr->get_Next();
                }
                        
                node_befo->set_Next(nullptr);
                tail = node_befo;
                delete node_curr;
            }
        }

        // Num > 1
        else
        {
            // There is 1 node
            if(head == tail)
            {
                delete head;
                head = tail = nullptr;

                if(num != 1) {return W_DEL_NUM;}
            }

            else
            {
                // Delete n times
                for(int i = 0; i < num; ++i)
                {
                    // List is empty before completing deleting n nodes
                    if(delete_Tail(head, tail, 1) != E_INS_OK) {return W_DEL_NUM;}
                }
            }
        }

    return E_INS_OK;
                
#endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_Before(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0)
 * \brief               Delete <num> nodes before <pos>th node
 * \param   list           List includes
 * \param   list        List includes
 * \param   num         Number of nodes will be deleted
 * \param   pos         Position for deleting nodes
 * \return              void
**/
template <class data_t>
errDel_t delete_Before(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0)
{
    #if true

        if(num  == 0)       {return E_DEL_NUM;  }
        if(list->get_Head() == nullptr) {return E_INS_HEAD; }
        if(tail == nullptr) {return E_INS_TAIL; }



        return E_INS_OK;
        
    #endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_After(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0)
 * \brief               Delete <num> nodes after <pos>th node
 * \param   list           List includes
 * \param   list        List includes
 * \param   num         Number of nodes will be deleted
 * \param   pos         Position for deleting nodes
 * \return              void
**/
template <class data_t>
errDel_t delete_After(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0)
{
    #if true

        if(num  == 0)       {return E_DEL_NUM;  }
        if(list->get_Head() == nullptr) {return E_INS_HEAD; }
        if(tail == nullptr) {return E_INS_TAIL; }



        return E_INS_OK;
        
    #endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_Node(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0)
 * \brief               Delete <pos>th node <num>th times
 * \param   list           List includes
 * \param   list        List includes
 * \param   num         Number of times deleting node
 * \param   pos         Position of node
 * \return              void
**/
template <class data_t>
errDel_t delete_Node(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0)
{
    #if true

        if(num  == 0)       {return E_DEL_NUM;  }
        if(list->get_Head() == nullptr) {return E_INS_HEAD; }
        if(tail == nullptr) {return E_INS_TAIL; }

        if(num == 1)
        {
            if(head == tail)
            {
                delete head;
                head = tail = nullptr;
            }

            else if(pos == 0)
            {
                doubleNode_t<data_t> *node_befo = head;
                doubleNode_t<data_t> *node_curr = list->get_Head();

                node_befo = node_curr;
                node_curr = node_curr->get_Next();
                delete node_befo;

                head = node_curr; 
            }

            else 
            {
                doubleNode_t<data_t> *node_befo = head;
                doubleNode_t<data_t> *node_curr = list->get_Head();

                int i = 0;
                while(node_curr->get_Next() != list->get_Head() && i < pos)
                {
                    node_befo = node_curr;
                    node_curr = node_curr->get_Next();
                    ++i;
                }

                if(node_curr->get_Next() == list->get_Head())
                {
                    if(i < pos) {return E_INS_POS;}

                    else if(i == pos)
                    {
                        node_befo->set_Next(nullptr);
                        tail = node_befo;
                        delete node_curr;
                    }
                }

                else
                {
                    node_befo->set_Next(node_curr->get_Next());
                    delete node_curr;                        
                }
            }
        }

        // Num > 1
        else
        {
            // There is 1 node
            if(head == tail)
            {
                delete head;
                head = tail = nullptr;

                if(num > 1) {return W_DEL_NUM;}
            }

            else
            {
                // Delete 1 node n times
                for(int i = 0; i < num; ++i)
                {
                    errDel_t ret = delete_Node(head, tail, 1, pos);
                    if(ret != E_INS_OK) {return ret;}
                }
            }
        }
                
        return E_INS_OK;
                
    #endif
}


/**
 * \fn                  template <class data_t> errDel_t delete_All(doubleList_t<data_t> *&list)
 * \brief               Delete all nodes of list
 * \param   list           List includes
 * \param   list        List includes
 * \return              void
**/
template <class data_t>
errDel_t delete_All(doubleList_t<data_t> *&list)
{
    #if true

        if(list->get_Head() == nullptr) {return E_INS_HEAD; }
        if(tail == nullptr) {return E_INS_TAIL; }

        doubleNode_t<data_t> *node_curr = list->get_Head();

        // There are many nodes
        while(head->get_Next() != nullptr)
        {
            node_curr = head;
            head = head->get_Next();
            delete node_curr;
        }

        // There is one node
        delete head;
        head = tail = nullptr;

        return E_INS_OK;

#endif
}




/*** Overide ***/








/* -----------------------------------------------------------------------------
/* Member functions of class template
/*
/* -------------------------------------------------------------------------- */

/**
 * \fn                  template <class data_t> doubleNode_t<data_t>::doubleNode_t<data_t>()
 * \brief               Initialize data_ is set by hand, pointer to next node is nullptr
 * \param               void
 * \return              void
**/
template <class data_t>
doubleNode_t<data_t>::doubleNode_t<data_t>()
{
    if(true)
    {
        this->ptr_next_ = nullptr;
        this->ptr_prev_ = nullptr;
    }
}

/**
 * \fn                  template <class data_t> void doubleNode_t<data_t>::set_Next(doubleNode_t<data_t> *next)
 * \brief               Set pointer to next node
 * \param   next    Pointer to next node
 * \return              void
**/
template <class data_t>
void doubleNode_t<data_t>::set_Next(doubleNode_t<data_t> *next)
{
    if(true)
    {
        this->ptr_next_ = next;
    }
}

/**
 * \fn                  template <class data_t> void doubleNode_t<data_t>::set_Prev(doubleNode_t<data_t> *prev)
 * \brief               Set pointer to previous node
 * \param   prev    Pointer to previous node
 * \return              void
**/
template <class data_t>
void doubleNode_t<data_t>::set_Prev(doubleNode_t<data_t> *prev)
{
    if(true)
    {
        this->ptr_prev_ = prev;
    }
}


/**
 * \fn                  template <class data_t> doubleNode_t<data_t> *doubleNode_t<data_t>::get_Next()
 * \brief               Get pointer to next node
 * \param               void
 * \return              Pointer to the next node
**/
template <class data_t>
doubleNode_t<data_t> *doubleNode_t<data_t>::get_Next()
{
    if(true)
    {
        return ptr_next_;
    }
}


/**
 * \fn                  template <class data_t> doubleNode_t<data_t> *doubleNode_t<data_t>::get_Prev()
 * \brief               Get pointer to previous node
 * \param               void
 * \return              Pointer to the previous node
**/
template <class data_t>
doubleNode_t<data_t> *doubleNode_t<data_t>::get_Prev()
{
    if(true)
    {
        return ptr_prev_;
    }
}



/* ---------------------------------------------------------------- */



/**
 * \fn                  template <class data_t> doubleList_t<data_t>::doubleList_t<data_t>()
 * \brief               Initialize an empty list
 * \param               void
 * \return              void
**/
template <class data_t>
doubleList_t<data_t>::doubleList_t<data_t>()
{   
    #if true

        this->ptr_head_ = nullptr;
        this->ptr_tail_ = nullptr;

    #endif
}

/**
 * \fn                  template <class data_t> void doubleList_t<data_t>::set_Head(doubleList_t<data_t> *head)
 * \brief               Set pointer to head of list
 * \param   head        Pointer to head of list
 * \return              void
**/
template <class data_t>
void doubleList_t<data_t>::set_Head(doubleNode_t<data_t> *head)
{
    #if true

        this->ptr_head_ = head;

    #endif
}

/**
 * \fn                  template <class data_t> void doubleList_t<data_t>::set_Tail(doubleList_t<data_t> *tail)
 * \brief               Set pointer to tail of list
 * \param   tail        Pointer to tail of list
 * \return              void
**/
template <class data_t>
void doubleList_t<data_t>::set_Tail(doubleNode_t<data_t> *tail)
{
    #if true

        this->ptr_tail_ = tail;
        
    #endif
}


/**
 * \fn                  template <class data_t> doubleNode_t<data_t> *doubleList_t<data_t>::get_Head()
 * \brief               Get pointer to head of list
 * \param               void
 * \return              Pointer to the head of list
**/
template <class data_t>
doubleNode_t<data_t> *doubleList_t<data_t>::get_Head()
{
    #if true

        return ptr_head_;
    
    #endif
}


/**
 * \fn                  template <class data_t> doubleNode_t<data_t> *doubleList_t<data_t>::get_Tail()
 * \brief               Get pointer to tail of list
 * \param               void
 * \return              Pointer to the tail of list
**/
template <class data_t>
doubleNode_t<data_t> *doubleList_t<data_t>::get_Tail()
{
    #if true

        return ptr_tail_;
    
    #endif
}








/* -----------------------------------------------------------------------------
/* Support functions
/*
/* -------------------------------------------------------------------------- */



/**
 * \fn                  template <class data_t> errMov_t move_Next(doubleList_t<data_t> *&list, doubleNode_t<data_t> *&node, unsigned n)
 * \brief               Move specific node to next node <n> times
 * \param   list        List includes specific node
 * \param   node        Specific node
 * \param   n           Number of times current node is moved
 * \return              Errors when using this function
**/
template <class data_t>
errMov_t move_Next(doubleList_t<data_t> *&list, doubleNode_t<data_t> *&node, unsigned n)
{
    #if true
        if(list == nullptr) {return E_MOV_LIST;}
        if(node == nullptr) {return E_MOV_NODE;}
        if(n < 0)           {return E_MOV_ERR; }

        unsigned i = 0;
        while(i < n && node->get_Next() != list->get_Head())
        {
            node = node->get_Next();
            ++i;
        }

        // Specific node is at tail of list
        if(node->get_Next() == list->get_Head())
        {
            // Position is greater than tail
            if(i < n) {return E_MOV_OVER;}

            // Position is tail of list
            return W_MOV_TAIL;
        }

        // pos is from head to tail-1
        return E_MOV_OK;

    #endif
}



/* ---------------------------------------------------------------- */



/**
 * \fn                  template <class data_t> void link_TailHead(doubleList_t<data_t> *&list)
 * \brief               Link the tail of list to the head of list
 * \param   list        List has the tail you want to link to the head
 * \return              void
**/
template <class data_t>
void link_TailHead(doubleList_t<data_t> *&list)
{
    #if true

        list->get_Tail()->set_Next(list->get_Head());
        list->get_Head()->set_Prev(list->get_Tail());

    #endif
}


/**
 * \fn                  template <class data_t> void link_TwoNode(doubleNode_t<data_t> *node_1, doubleNode_t<data_t> *node_2)
 * \brief               Create a double link between node_1 and node_2
 * \param   node_1      Node 1
 * \param   node_2      Node 2
 * \return              void
**/
template <class data_t>
void link_TwoNode(doubleNode_t<data_t> *node_1, doubleNode_t<data_t> *node_2)
{
    #if true

        node_1->set_Next(node_2);
        node_2->set_Prev(node_1);

    #endif
}



/* ---------------------------------------------------------------- */



/**
 * \fn                  template <class T> void swap(T &var1, T &var2)
 * \brief               Swap values of two variables
 * \param   var1        Variable 1
 * \param   var2        Variable 2
 * \return              void
**/
template <class T>
void swap(T &var1, T &var2)
{
    #if true

        T temp = var1;
        var1   = var2;
        var2   = temp;

    #endif
}


/**
 * \fn                  template <class data_t> void doNothing(data_t &data_)
 * \brief               Do nothing
 * \param               void
 * \return              void
**/
template <class data_t>
void doNothing(data_t &data_)
{
    
}

#endif // DOUBLE_LIST_H
