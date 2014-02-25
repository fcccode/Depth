/*!
 *  \file    CRandomBufferIntegerIterator.hpp Random integer numbers buffer
 *           non constant iterator definitions. It gives ability to get
 *           and modify random integer numbers buffer items.
 *  \brief   Random integer numbers buffer non constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Random integer numbers buffer non constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random iterators
    VERSION:   1.0
    CREATED:   02.03.2009 02:15:30

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

    This program is distributed in the  hope  that  it  will  be  useful,  but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General  Public  License
    for more details.

    You should have received a copy of the GNU General  Public  License  along
    with this program; if not, write to the Free Software Foundation, Inc., 59
    Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
/*--------------------------------------------------------------------------*/
/*
    FILE ID: $Id$

    CHANGE LOG:

    $Log$
*/
/*==========================================================================*/
#ifndef __CRANDOMBUFFERINTEGERITERATOR_HPP__
#define __CRANDOMBUFFERINTEGERITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIterator.hpp>
#include <Depth/include/common/iterators/IIteratorMoveBackward.hpp>
#include <Depth/include/random/CRandomBufferInteger.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Random integer numbers buffer non constant iterator class.
/*!
    Random integer numbers buffer  non  constant  iterator  represents  random
    integer numbers buffer iterations  method.  With  this  iterator  you  can
    perform looking into random integer numbers buffer items and  also  modify
    them.
*/
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
class CRandomBufferIntegerIterator :
  public NCommon::NIterators::IIterator<CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>, Tuint, Tuint, CRandomBufferInteger<T_RandomGenerator, T_DequeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveBackward<CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>, Tuint, Tuint, CRandomBufferInteger<T_RandomGenerator, T_DequeContainer, T_Allocator> >
{
  // Friend class: Random integer numbers buffer class (CRandomBufferInteger).
  friend class CRandomBufferInteger<T_RandomGenerator, T_DequeContainer, T_Allocator>;
  // Friend class: Random integer numbers buffer constant iterator class (CRandomBufferIntegerIteratorConst).
  friend class CRandomBufferIntegerIteratorConst<T_RandomGenerator, T_DequeContainer, T_Allocator>;

  //! Type for MConceptDeque constraint checking.
  typedef T_DequeContainer<Tuint, T_Allocator> TDequeContainerCheckType;
  //! Type for MConceptDequeConst constraint checking.
  typedef T_DequeContainer<Tuint, T_Allocator> TDequeContainerConstCheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator> TDepthCheckType;

  // Check T_DequeContainer template argument constraint to be a non constant deque container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptDeque, TDequeContainerCheckType);
  // Check T_DequeContainer template argument constraint to be a constant deque container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptDequeConst, TDequeContainerConstCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CRandomBufferIntegerIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef Tuint TType;
  //! Iterator return type.
  typedef Tuint TReturn;
  //! Iterator container type.
  typedef CRandomBufferInteger<T_RandomGenerator, T_DequeContainer, T_Allocator> TContainer;
  //! Iterator base type.
  typedef CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator> TIterator;

  //! Iterator allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CRandomBufferIntegerIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomBufferIntegerIterator class.
  */
  CRandomBufferIntegerIterator(const CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomBufferIntegerIterator();

  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <class T_OtherRandomGenerator, template <typename, class> class T_OtherDequeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CRandomBufferIntegerIterator<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator>& a_crInstance1, const CRandomBufferIntegerIteratorConst<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <class T_OtherRandomGenerator, template <typename, class> class T_OtherDequeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CRandomBufferIntegerIteratorConst<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator>& a_crInstance1, const CRandomBufferIntegerIterator<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <class T_OtherRandomGenerator, template <typename, class> class T_OtherDequeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CRandomBufferIntegerIterator<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator>& a_crInstance1, const CRandomBufferIntegerIterator<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <class T_OtherRandomGenerator, template <typename, class> class T_OtherDequeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CRandomBufferIntegerIterator<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator>& a_crInstance1, const CRandomBufferIntegerIteratorConst<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <class T_OtherRandomGenerator, template <typename, class> class T_OtherDequeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CRandomBufferIntegerIteratorConst<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator>& a_crInstance1, const CRandomBufferIntegerIterator<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <class T_OtherRandomGenerator, template <typename, class> class T_OtherDequeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CRandomBufferIntegerIterator<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator>& a_crInstance1, const CRandomBufferIntegerIterator<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>& operator = (const CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherRandomGenerator, template <typename, class> class T_OtherDequeContainer, class T_OtherAllocator>
  friend CRandomBufferIntegerIterator<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator> operator + (const CRandomBufferIntegerIterator<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <class T_OtherRandomGenerator, template <typename, class> class T_OtherDequeContainer, class T_OtherAllocator>
  friend CRandomBufferIntegerIterator<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator> operator - (const CRandomBufferIntegerIterator<T_OtherRandomGenerator, T_OtherDequeContainer, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Set another CRandomBufferIntegerIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomBufferIntegerIterator class.
  */
  void set(const CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator> getBackward() const;

  // IIteratorConst interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual CRandomBufferInteger<T_RandomGenerator, T_DequeContainer, T_Allocator>& getContainerRef() const;
  virtual CRandomBufferInteger<T_RandomGenerator, T_DequeContainer, T_Allocator>* getContainerPtr() const;
  virtual Tuint& getValueRef() const;
  virtual Tuint* getValuePtr() const;

  // IIteratorMoveBackward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);

  //! Serialize CRandomBufferIntegerIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomBufferIntegerIterator class instances.
  /*!
      \param a_rInstance - Reference to another CRandomBufferIntegerIterator class instance.
  */
  void swap(CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>& a_rInstance);

private:
  CRandomBufferInteger<T_RandomGenerator, T_DequeContainer, T_Allocator>* m_pContainer; //!< Pointer to the iterator container.
  typename T_DequeContainer<Tuint, T_Allocator>::TIterator                m_Iterator;   //!< Base deque container non constant iterator.

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CRandomBufferIntegerIterator(CRandomBufferInteger<T_RandomGenerator, T_DequeContainer, T_Allocator>* a_pContainer);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* ITERATOR TRAITS SPECIALIZATION DECLARATIONS                              */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*--------------------------------------------------------------------------*/
//! Traits meta-class: random integer numbers buffer non constant iterator's traits specialization.
template <class T_RandomGenerator, template <typename, class> class T_DequeContainer, class T_Allocator>
class MTraitsIterator<NRandom::NIterators::CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator> > :
  public MType<NRandom::NIterators::CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NRandom::NIterators::CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NRandom::NIterators::CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NRandom::NIterators::CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NRandom::NIterators::CRandomBufferIntegerIterator<T_RandomGenerator, T_DequeContainer, T_Allocator>::TIterator iterator;

  static const Tbool isConst             = false; //!< Is iterator constant?
  static const Tbool isCircled           = true;  //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = false; //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = false; //!< Is iterator supports associative moving?
  static const Tbool isMoveTree          = false; //!< Is iterator supports tree moving?
  static const Tbool isMoveGraph         = false; //!< Is iterator supports graph moving?
  static const Tbool isInsertForward     = false; //!< Is iterator supports forward inserting?
  static const Tbool isInsertBackward    = false; //!< Is iterator supports forward and backward inserting?
  static const Tbool isInsertRandom      = false; //!< Is iterator supports random inserting?
  static const Tbool isInsertAssociative = false; //!< Is iterator supports associative inserting?
  static const Tbool isInsertTree        = false; //!< Is iterator supports tree inserting?
  static const Tbool isInsertGraph       = false; //!< Is iterator supports graph inserting?
  static const Tbool isRemoveForward     = false; //!< Is iterator supports forward removing?
  static const Tbool isRemoveBackward    = false; //!< Is iterator supports forward and backward removing?
  static const Tbool isRemoveRandom      = false; //!< Is iterator supports random removing?
  static const Tbool isRemoveAssociative = false; //!< Is iterator supports associative removing?
  static const Tbool isRemoveTree        = false; //!< Is iterator supports tree removing?
  static const Tbool isRemoveGraph       = false; //!< Is iterator supports graph removing?
};
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/iterators/CRandomBufferIntegerIterator.inl>
/*==========================================================================*/
#endif
