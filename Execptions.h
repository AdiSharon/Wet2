//
// Created by Adi Sharon on 5/1/2018.
//

#ifndef EXECPTIONS_H
#define EXECPTIONS_H

#include <stdexcept>

namespace DS {

    class DSExceptions {};

    namespace Oasis {

        class OasisException : public DSExceptions {};
        class OasisMemoryProblemException : public OasisException {};
        class OasisInvalidInputException : public OasisException {};
        class OasisFailureException : public OasisException {};

    }

    namespace Tree {
        class TreeExceptions : public DSExceptions {};
        class TreeMemoryProblemException : public TreeExceptions {};
        class TreeInvalidInput : public TreeExceptions {};
        class TreeDataAlreadyExists : public TreeExceptions {};
        class TreeNodeDoesNotExit : public TreeExceptions {};
        class TreeBFProblem : public TreeExceptions {};
        class TreeSuccess : public TreeExceptions {};
    }

    namespace MinHeap {
        class HeapExceptions: public DSExceptions {};
        class HeapInvalidInput : public HeapExceptions {};
        class HeapEmpty : public HeapExceptions{};

    }

    namespace List {
        class ListExceptions: public DSExceptions {};
        class ElementNotFound : public ListExceptions {};
        class ListInvalidInput : public ListExceptions {};
        class ListEmpty : public ListExceptions{};
    }

    namespace ChainHash {
        class ChainHashExceptions: public DSExceptions {};
        class ChainHashInvalidInput : public ChainHashExceptions {};
        class ChainHashEmpty : public ChainHashExceptions{};
        class ChainHashElementNotFound : public ChainHashExceptions {};
        class ChainHashElementAlreadyExists : public ChainHashExceptions {};

    }
}


#endif //EXECPTIONS_H
