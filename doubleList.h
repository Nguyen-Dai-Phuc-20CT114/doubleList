/** ------------------------------------------------------------
 * Copyright (c) 2021 Phuc Nguyen
 *
 * $Author:             Phuc Nguyen
 * $Date:               November 12, 2021
 * $Version:            2.1.0
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
 * 
 *      When using create_ fucntions, you must add <data_type_t> behind them
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
#define nullptr     0
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



// create modes: FORWARD and REVERSE
typedef enum
{
    // The new node will be added after the specific node
    FORWARD     =   0,

    // The new node will be added before the specific node
    REVERSE     =   1,

} creMode_t;


// add modes: STACK and QUEUE
typedef enum
{
    // The ealier node, the farther specific node
    // First created, last added
    STACK       =   0,

    // The earlier node, the closer specific node
    // First created, first added
    QUEUE       =   1,

} addMode_t;



// Error when using add functions
typedef enum
{

    // Function is ok
    E_ADD_OK    = E_OK,

    // List is not exist
    E_ADD_LIST  = E_LIST,

    // Head of list is nullptr
    E_ADD_HEAD  = E_HEAD,

    // Tail of list is nullptr
    E_ADD_TAIL  = E_TAIL,

    // Number of nodes need to be created is 0
    E_ADD_NUM   = E_NUM,

    // Argument <position> is invalid
    E_ADD_POS  = E_POS,
    
}errAdd_t;



// Error when using insert functions
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

    // Position is greater than number of nodes
    E_INS_POS   = E_POS,

    // Node is nullptr
    E_INS_NODE  = E_NODE,
    
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
doubleList_t<data_t> *create_List(unsigned num = 0, void(*setTask)(data_t &data_) = doNothing, creMode_t creMode = FORWARD);




template <class data_t>
int traverse_List(doubleList_t<data_t> *list, void (*subTask)(data_t &data_));




template <class data_t>
void arrange_List(doubleList_t<data_t> *list, bool (*conTask)(data_t data1_, data_t data2_));




template <class data_t>
doubleNode_t<data_t> *get_Node(doubleList_t<data_t> *list, unsigned pos = 0);

template <class data_t>
doubleNode_t<data_t> *get_Node(doubleList_t<data_t> *list, bool(*conTask)(data_t data_), unsigned from = 0);

// template <class data_t>
// doubleNode_t<data_t> *get_Tail(doubleList_t<data_t> *list);

template <class data_t>
int get_Index(doubleList_t<data_t> *list, doubleNode_t<data_t> node);

template <class data_t>
int get_Index(doubleList_t<data_t> *list, bool (*conTask)(data_t data_));




template <class data_t>
errAdd_t add_Head(doubleList_t<data_t> *&list, unsigned num = 1, addMode_t addMode = STACK, void(*setTask)(data_t &data_) = doNothing);

template <class data_t>
errAdd_t add_Tail(doubleList_t<data_t> *&list, unsigned num = 1, void(*setTask)(data_t &data_) = doNothing);

template <class data_t>
errAdd_t add_Before(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0, addMode_t addMode = STACK, void(*setTask)(data_t &data_) = doNothing);

template <class data_t>
errAdd_t add_After(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0, void(*setTask)(data_t &data_) = doNothing);




template <class data_t>
errIns_t insert_Head(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode);

template <class data_t>
errIns_t insert_Tail(doubleList_t<data_t> *&list, doubleNode_t<data_t> *&newNode);

template <class data_t>
errIns_t insert_Before(doubleList_t<data_t> *&list, doubleNode_t<data_t> *&newNode, unsigned pos = 0);

template <class data_t>
errIns_t insert_After(doubleList_t<data_t> *&list, doubleNode_t<data_t> *&newNode, unsigned pos = 0);

template <class data_t>
errIns_t insert_List(doubleNode_t<data_t> *&node1, doubleNode_t<data_t> *&node2, doubleList_t<data_t> *&newList);




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
void link_TwoNode(doubleNode_t<data_t> *node1, doubleNode_t<data_t> *node2);




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
// errAdd_t add_Before(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0, addMode_t addMode = STACK, void(*setTask)(data_t &data_) = doNothing);

// template <class data_t>
// errAdd_t add_After(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0);




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
 * \fn                  template <class data_t> doubleList_t<data_t> *create_List(unsigned num = 0, void(*setTask)(data_t &data_) = doNothing, creMode_t creMode = FORWARD)
 * \brief               Create a brand new list having num nodes
 * \param   num         Number of nodes will be created
 * \param   setTask     Pointer to a function which set data_ for each node
 * \param   addMode     FORWARD or REVERSE
 * \return              Pointer to the last added node
**/
template <class data_t>
doubleList_t<data_t> *create_List(unsigned num = 0, void(*setTask)(data_t &data_) = doNothing, creMode_t creMode = FORWARD)
{
    #if true

        if(num < 0) {return nullptr;}


        doubleList_t<data_t> *list_new  = new doubleList_t();
        list_new->set_Head(nullptr);
        list_new->set_Tail(nullptr);

        for(int i = 0; i < num; ++i)
        {
            doubleNode_t<data_t> *node_new = create_Node<data_t>(nullptr, nullptr, setTask);

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

                // Add new node after the tail
                if(creMode == FORWARD)
                {
                    // oldTail <-> tail <-> head
                    list_new->set_Tail(node_new);
                }

                // if(creMode == REVERSE)
                // Add new node before the head
                else
                {
                    // tail <-> newHead <-> oldHead
                    list_new->set_Head(node_new);
                }
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
            while(node_2 != list->get_Head());


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

        /*** Get node at <from> ***/

        doubleNode_t<data_t> *node_curr = list->get_Head();
        
        if(move_Next(list, node_curr, from) == E_MOV_OVER) {return nullptr;}


        /*** Find node base on conTask (condition task) ***/

        bool cond = (*conTask)(node_curr->data_);
        
        while(!cond && node_curr->get_Next() != list->get_Head())
        {
            node_curr = node_curr->get_Next();
            cond = (*conTask)(node_curr->data_);
        }


        /*** Return wanted node if it's exist ***/

        if(cond) {return node_curr;}

        return nullptr;

    #endif
}


// /**
//  * \fn                  template <class data_t> doubleNode_t<data_t> *get_Tail(doubleList_t<data_t> *list)
//  * \brief               Get pointer to tail of double list
//  * \param   list        List include wanted tail
//  * \return              Pointer to tail of double list
// **/
// template <class data_t>
// doubleNode_t<data_t> *get_Tail(doubleList_t<data_t> *list)
// {
//     #if true

//         if(list == nullptr)             {return nullptr;}
//         if(list->get_Head() == nullptr) {return nullptr;}

//         doubleNode_t<data_t> *tail = list->get_Head();

//         while(tail->get_Next() != list->get_Head())
//         {
//             tail = tail->get_Next();
//         }

//         return tail;
    
//     #endif
// }


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
        if(list->get_Head() == nullptr) {return -2;}
        if(list->get_Tail() == nullptr) {return -3;}

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
        if(list->get_Head() == nullptr) {return -2;}
        if(list->get_Tail() == nullptr) {return -3;}

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
 * \fn                  template <class data_t> errAdd_t add_Head(doubleList_t<data_t> *&list, unsigned num = 1, addMode_t addMode = STACK, void(*setTask)(data_t &data_) = doNothing)
 * \brief               Add new nodes at head of double list
 * \param   list        List is added new head
 * \param   num         Number of nodes will be added
 * \param   addMode     How to add new nodes: QUEUE or STACK
 * \param   setTask     Pointer to the function which set data_ of each added node
 * \return              Error when using this function
**/
template <class data_t>
errAdd_t add_Head(doubleList_t<data_t> *&list, unsigned num = 1, addMode_t addMode = STACK, void(*setTask)(data_t &data_) = doNothing)
{
    #if true

        if(list == nullptr) {return E_ADD_LIST;}
        if(num <= 0)        {return E_ADD_NUM;}


        /**
         * Create a new list including new nodes
         * 
         * ***************************************************
         * addMode == STACK
         *    - New list is like: node_1 <-> node_2 <-> node_3
         *    - So create mode is FORWARD
         *    - STACK == FORWARD == 0
         * 
         * addMode == QUEUE
         *    - New list is like: node_3 <-> node_2 <-> node_1
         *    - So create mode is REVERSE
         *    - QUEUE == REVERSE == 1
         *
        **/
        doubleList_t<data_t> *list_new = create_List<data_t>(num, setTask, (creMode_t)addMode);


        /**
         * Add the list of new nodes before the head of origin list
         * 
         * ************************************************
         * If the origin list doesn't have any node
         *    - Its head is head of new list
         *    - Its tail is tail of new list
         * 
         * If the origin list has only 1 node
         *    - Insert new list before head of origin list
         *    - Its head is head of new list
         *    - Its tail is not changed
         * 
         * If the origin list has many nodes
         *    - Insert new list between tail and head of origin list
         *    - Head of new list is new head of origin list now
         * 
        **/

        // If the origin list doesn't have any node
        if(list->get_Head == nullptr)
        {
           list->set_Head(list_new->get_Head());
           list->set_Tail(list_new->get_Tail());
        }

        // If the origin list has only 1 node
        else if(list->get_Head() == list->get_Tail())
        {
            //             tail
            // newList <-> head
            link_TwoNode(list_new->get_Tail(), list->get_Head());

            //                     tail
            // newHead <-> ... <-> oldHead
            list->set_Head(list_new->get_Head());

            // tail <-> newHead
            link_TailHead(list);
        }

        // If the origin list has many nodes
        else
        {
            // tail <-> newList <-> head
            insert_List(list->get_Tail(), list->get_Head(), list_new);

            // tail <-> newHead <-> ... <-> oldHead
            list->set_Head(list_new->get_Head());
        }

        delete list_new;
        return E_ADD_OK;

    #endif
}


/**
 * \fn                  template <class data_t> errAdd_t add_Tail(doubleList_t<data_t> *&list, unsigned num = 1, void(*setTask)(data_t &data_) = doNothing)
 * \brief               Add new nodes at tail of double list
 * \param   list        List is added new tail
 * \param   num         Number of nodes will be added
 * \param   setTask     Pointer to the function which set data_ of each added node
 * \return              Error when using this function
**/
template <class data_t>
errAdd_t add_Tail(doubleList_t<data_t> *&list, unsigned num = 1, void(*setTask)(data_t &data_) = doNothing)
{
    #if true

        if(list == nullptr) {return E_ADD_LIST;}
        if(num <= 0)        {return E_ADD_NUM;}  

        // Create a new list including new nodes
        doubleList_t<data_t> *list_new = create_List(num, setTask, FORWARD);


        /*** Add the list of new nodes after the tail of origin list **/
        /* 
         * ************************************************
         * If the origin list doesn't have any node
         *    - Its head is head of new list
         *    - Its tail is tail of new list
         * 
         * If the origin list has only 1 node
         *    - Insert new list after tail of origin list
         *    - Its head is not changed
         *    - Its tail is tail of new list
         * 
         * If the origin list has many nodes
         *    - Insert new list between tail and head of origin list
         *    - Tail of new list is new tail of origin list now
         * 
        **/

        // If the origin list doesn't have any node
        if(list->get_Head == nullptr)
        {
           list->set_Head(list_new->get_Head());
           list->set_Tail(list_new->get_Tail());
        }

        // If the origin list has only 1 node
        else if(list->get_Head() == list->get_Tail())
        {
            // head
            // tail <-> newList
            link_TwoNode(list->get_Tail(), list_new->get_Head());

            // head
            // oldTail <-> ... <-> newTail
            list->set_Head(list_new->get_Head());

            // newTail <-> head
            link_TailHead(list);
        }

        // If the origin list has many nodes
        else
        {
            // tail <-> newList <-> head
            insert_List(list->get_Tail(), list->get_Head(), list_new);

            // oldTail <-> ... <-> newTail <-> head
            list->set_Tail(list_new->get_Tail());
        }

        delete list_new;
        return E_ADD_OK;

    #endif
}


/**
 * \fn                  template <class data_t> errAdd_t add_Before(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0, addMode_t addMode = STACK, void(*setTask)(data_t &data_) = doNothing)
 * \brief               Add new nodes before a specified position
 * \param   list        List is added new nodes
 * \param   num         Number of nodes will be added
 * \param   pos         Position for add nodes
 * \param   addMode     How to add new nodes: QUEUE or STACK
 * \param   setTask     Pointer to the function which set data_ of each added node
 * \return              Error when using this function
**/
template <class data_t>
errAdd_t add_Before(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0, addMode_t addMode = STACK, void(*setTask)(data_t &data_) = doNothing)
{
    #if true

        if(list == nullptr)             {return E_ADD_LIST;}
        if(list->get_Head() == nullptr) {return E_ADD_HEAD;}
        if(list->get_Tail() == nullptr) {return E_ADD_TAIL;}
        if(num <= 0)                    {return E_ADD_NUM; }
        if(pos <  0)                    {return E_ADD_POS; }


        // The specific node is head of origin list
        if(pos == 0)
        {
            return add_Head(list, num, addMode, setTask);
        }

        else
        {
            /*** Get specific node ***/
            doubleNode_t<data_t> *node_spec = list->get_Head();

            if(move_Next(list, node_spec, pos) == E_MOV_OVER) {return E_ADD_POS;}


            /*** Get node before specific node ***/
            doubleNode_t<data_t> *node_prev = node_spec->get_Prev();


            /*** Create a new list including new nodes ***/
            /* 
             * ***************************************************
             * addMode == STACK
             *    - New list is like: node_1 <-> node_2 <-> node_3
             *    - So create mode is FORWARD
             *    - STACK == FORWARD == 0
             * 
             * addMode == QUEUE
             *    - New list is like: node_3 <-> node_2 <-> node_1
             *    - So create mode is REVERSE
             *    - QUEUE == REVERSE == 1
             *
            **/
            doubleList_t<data_t> *list_new = create_List<data_t>(num, setTask, (creMode_t)addMode);

            /*** Insert the new list between the previous specific node and specific node ***/
            insert_List(node_prev, node_spec, list_new);

            delete list_new;
            return E_ADD_OK;
        }
    
    #endif
}


/**
 * \fn                  template <class data_t> errAdd_t add_After(doubleList_t<data_t> *&list, unsigned num=1, unsigned pos=0)
 * \brief               Add new nodes after a specific position
 * \param   list        List is added new nodes
 * \param   num         Number of nodes will be added
 * \param   pos         Position for add nodes
 * \param   setTask     Pointer to the function which set data_ of each added node
 * \return              Error when using this function
**/
template <class data_t>
errAdd_t add_After(doubleList_t<data_t> *&list, unsigned num = 1, unsigned pos = 0, void(*setTask)(data_t &data_) = doNothing)
{
    #if true

        if(list == nullptr)             {return E_ADD_LIST;}
        if(list->get_Head() == nullptr) {return E_ADD_HEAD;}
        if(list->get_Tail() == nullptr) {return E_ADD_TAIL;}
        if(num <= 0)                    {return E_ADD_NUM; }
        if(pos <  0)                    {return E_ADD_POS; }
        


        /*** Get specific node ***/

        doubleNode_t<data_t> *node_spec = list->get_Head();

        errMov_t errMove = move_Next(list, node_spec, pos);

        if(errMove == E_MOV_OVER) {return E_ADD_POS;}



        /*** The specific node is tail of origin list ***/
        if(errMove == W_MOV_TAIL)
        {
            return add_Tail(list, num, setTask);
        }



        /*** The specific node isn't tail of origin list ***/

        // Get the node after specific node
        doubleNode_t<data_t> *node_next = node_spec->get_Next();

        // Create a list including new nodes
        doubleList_t<data_t> *list_new = create_List(num, setTask, FORWARD);

        // Insert the new list between the previous specific node and specific node
        insert_List(node_spec, node_next, list_new);

        delete list_new;
        return E_ADD_OK;

    #endif
}



/* ---------------------------------------------------------------- */



/**
 * \fn                  template <class data_t> errIns_t insert_Head(doubleList_t<data_t> *&list, doubleNode_t<data_t> *&newNode)
 * \brief               Insert an existing node before the head of list
 * \param   list        List includes the inserted node
 * \param   newNode     Node is inserted
 * \return              Error when using insert functions
**/
template <class data_t>
errIns_t insert_Head(doubleList_t<data_t> *&list, doubleNode_t<data_t> *&newNode)
{
    #if true

        if(list    == nullptr)  {return E_INS_LIST;     }
        if(newNode == nullptr)  {return E_INS_NEW_NODE; }


        doubleNode_t<data_t> *node_new = newNode;


        // If the new node is in another list
        if(newNode->get_Next() != nullptr || newNode->get_Prev() != nullptr)
        {
            // Copy data of new list to another node
            node_new        = create_Node<data_t>();
            node_new->data_ = newNode->data_;
        }

        // If list is empty
        if(list->get_Head() == nullptr)
        {
            list->set_Head(node_new);
            list->set_Tail(node_new);
        }

        // If list has 1 node
        else if(list->get_Head() == list->get_Tail())
        {
            //             tail
            // newNode <-> head
            link_TwoNode(node_new, list->get_Head());

            // newNode     
            // newhead <-> tail
            list->set_Head(node_new);

            // newHead <-> tail <-> newHead
            link_TailHead(list);
        }

        // If list has many nodes
        // tail <-> head
        else
        {
            // tail <-> newNode -> nullptr
            link_TwoNode(list->get_Tail(), node_new);

            // tail <-> newNode <-> head
            link_TwoNode(node_new, list->get_Head());

            // tail <-> newHead <-> oldHead
            list->set_Head(node_new);
        }

        return E_INS_OK;

    #endif
}


/**
 * \fn                  template <class data_t> errIns_t insert_Tail(doubleList_t<data_t> *&list, doubleNode_t<data_t> *&newNode)
 * \brief               Insert an existing node after the tail of list
 * \param   list        List includes inserted node
 * \param   newNode     Node is inserted
 * \return              Error when using insert functions
**/
template <class data_t>
errIns_t insert_Tail(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode)
{
    #if true

        if(list    == nullptr)  {return E_INS_LIST;     }
        if(newNode == nullptr)  {return E_INS_NEW_NODE; }


        doubleNode_t<data_t> *node_new = newNode;


        // If the new node is in another list
        if(newNode->get_Next() != nullptr || newNode->get_Prev() != nullptr)
        {
            // Copy data of new list to another node
            node_new        = create_Node<data_t>();
            node_new->data_ = newNode->data_;
        }

        // If list is empty
        if(list->get_Head() == nullptr)
        {
            list->set_Head(node_new);
            list->set_Tail(node_new);
        }

        // If list has 1 node
        else if(list->get_Head() == list->get_Tail())
        {
            // head
            // tail <-> newNode
            link_TwoNode(list->get_Tail(), node_new);

            //          newNode
            // head <-> newTail   
            list->set_Tail(node_new);

            // head <-> newTail <-> head
            link_TailHead(list);
        }

        // If list has many nodes
        // tail <-> head
        else
        {
            // tail <-> newNode -> nullptr
            link_TwoNode(list->get_Tail(), node_new);

            // tail <-> newNode <-> head
            link_TwoNode(node_new, list->get_Head());

            // oldTail <-> newTail <-> head
            list->set_Tail(node_new);
        }

        return E_INS_OK;

    #endif
}


/**
 * \fn                  template <class data_t> errIns_t insert_Before(doubleList_t<data_t> *&list, doubleNode_t<data_t> *&newNode, unsigned pos = 0)
 * \brief               Insert an existing node before specific node in the list
 * \param   list           List includes
 * \param   newNode     Node is inserted
 * \param   pos         newNode is inserted before this position
 * \return              Error when using insert functions
**/
template <class data_t>
errIns_t insert_Before(doubleList_t<data_t> *&list, doubleNode_t<data_t> *&newNode, unsigned pos = 0)
{
    #if true

        if(list             == nullptr) {return E_INS_LIST;     }
        if(list->get_Head() == nullptr) {return E_INS_HEAD;     }
        if(list->get_Tail() == nullptr) {return E_INS_TAIL;     }
        if(newNode          == nullptr) {return E_INS_NEW_NODE; }



        // pos = head
        if(pos == 0) 
        {
            return insert_Head(list, newNode);
        }
        
        
        /*** Get specific node ***/
        doubleNode_t<data_t> *node_spec = list->get_Head();

        if(move_Next(list, node_spec, pos) == E_MOV_OVER) {return E_INS_POS;}


        // Get node before the specific node
        doubleNode_t<data_t> *node_prev = node_spec->get_Prev();

        // prev <-> newNode -> nullptr
        link_TwoNode(node_prev, node_new);

        // prev <-> newNode <-> spec
        link_TwoNode(node_new, node_spec);

        return E_INS_OK;

    #endif
}


/**
 * \fn                  template <class data_t> errIns_t insert_After(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode, unsigned pos = 0)
 * \brief               Insert an existing node after specific node in the list
 * \param   list        List includes newNode
 * \param   newNode     Node is inserted
 * \param   pos         newNode is inserted after this position
 * \return              Error when using insert functions
**/
template <class data_t>
errIns_t insert_After(doubleList_t<data_t> *&list, doubleNode_t<data_t> *newNode, unsigned pos = 0)
{
    #if true

        if(list             == nullptr) {return E_INS_LIST;     }
        if(list->get_Head() == nullptr) {return E_INS_HEAD;     }
        if(list->get_Tail() == nullptr) {return E_INS_TAIL;     }
        if(newNode          == nullptr) {return E_INS_NEW_NODE; }



        /*** Get specific node ***/

        doubleNode_t<data_t> *node_spec = list->get_Head();

        errMov_t errMove = move_Next(list, node_spec, pos);

        if(errMove == E_MOV_OVER) {return E_ADD_POS;}
        

        // pos = tail
        if(errMove == W_MOV_TAI) 
        {
            return insert_tail(list, newNode);
        }


        // Get node after the specific node
        doubleNode_t<data_t> *node_next = node_spec->get_Next();

        // spec <-> newNode -> nullptr
        link_TwoNode(node_spec, node_new);

        // spec <-> newNode <-> next
        link_TwoNode(node_new, node_next);

        return E_INS_OK;

    #endif
}


/**
 * \fn                  template <class data_t> errIns_t insert_List(doubleNode_t<data_t> *&node1, doubleNode_t<data_t> *&node2, doubleList_t<data_t> *&newList)
 * \brief               Insert an existing list between node1 and node2, node1 != node2
 * \param   node1       New list is insert after   node 1
 * \param   node2       New list is insert before  node 2
 * \param   newList     New list is insert between node 1 and node 2
 * \return              Error when using insert functions
**/
template <class data_t>
errIns_t insert_List(doubleNode_t<data_t> *&node1, doubleNode_t<data_t> *&node2, doubleList_t<data_t> *&newList)
{
    #if true

        if(node1             == nullptr) {return E_INS_NODE;}
        if(node2             == nullptr) {return E_INS_NODE;}
        if(newList           == nullptr) {return E_INS_LIST;}
        if(newList->get_Head == nullptr) {return E_INS_HEAD;}
        if(newList->get_Tail == nullptr) {return E_INS_TAIL;}

        // node1 <-> newList     node2
        link_TwoNode(node1, newList->get_Head());

        // node1 <-> newList <-> node2
        link_TwoNode(newList->get_Tail(), node2);

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
        doubleNode_t<data_t> *node_prev = head;
        doubleNode_t<data_t> *node_curr = list->get_Head();

        int i = 0;
        while(node_curr != nullptr && i < num)
        {
            node_prev = node_curr;
            node_curr = node_curr->get_Next();
            delete node_prev;
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
                doubleNode_t<data_t> *node_prev = head;
                doubleNode_t<data_t> *node_curr = list->get_Head();

                while(node_curr->get_Next() != list->get_Head())
                {
                    node_prev = node_curr;
                    node_curr = node_curr->get_Next();
                }
                        
                node_prev->set_Next(nullptr);
                tail = node_prev;
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
                doubleNode_t<data_t> *node_prev = head;
                doubleNode_t<data_t> *node_curr = list->get_Head();

                node_prev = node_curr;
                node_curr = node_curr->get_Next();
                delete node_prev;

                head = node_curr; 
            }

            else 
            {
                doubleNode_t<data_t> *node_prev = head;
                doubleNode_t<data_t> *node_curr = list->get_Head();

                int i = 0;
                while(node_curr->get_Next() != list->get_Head() && i < pos)
                {
                    node_prev = node_curr;
                    node_curr = node_curr->get_Next();
                    ++i;
                }

                if(node_curr->get_Next() == list->get_Head())
                {
                    if(i < pos) {return E_INS_POS;}

                    else if(i == pos)
                    {
                        node_prev->set_Next(nullptr);
                        tail = node_prev;
                        delete node_curr;
                    }
                }

                else
                {
                    node_prev->set_Next(node_curr->get_Next());
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
 * \fn                  template <class data_t> void link_TwoNode(doubleNode_t<data_t> *node1, doubleNode_t<data_t> *node2)
 * \brief               Create a double link between node1 and node2
 * \param   node1      Node 1
 * \param   node2      Node 2
 * \return              void
**/
template <class data_t>
void link_TwoNode(doubleNode_t<data_t> *node1, doubleNode_t<data_t> *node2)
{
    #if true

        node1->set_Next(node2);
        node2->set_Prev(node1);

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
