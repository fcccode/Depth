/*!
 *  \file    CMultisetIteratorConst.hpp Multiset constant iterator
 *           definitions. It gives ability to get multiset items.
 *  \brief   Multiset constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    26.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Multiset constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   26.09.2006 03:36:12

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
#ifndef __CMULTISETITERATORCONST_HPP__
#define __CMULTISETITERATORCONST_HPP__
/*==========================================================================*/
#include <Depth/include/common/iterators/IIteratorConst.hpp>
#include <Depth/include/common/iterators/IIteratorMoveAssociative.hpp>
#include <Depth/include/common/iterators/IIteratorMoveBackward.hpp>
#include <Depth/include/containers/CMultiset.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Multiset constant iterator class.
/*!
    Multiset constant iterator represents  multiset  iterations  method.  With
    this iterator you can perform looking into multiset items. Note  that  you
    cannot  modify multiset items with constant iterator. In this case use non
    constant multiset iterator.

    Serialization: Multiset constant iterator cannot be loaded.
*/
template <typename T_Key, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class CMultisetIteratorConst :
  public NCommon::NIterators::IIteratorConst<CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Key, CMultiset<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveAssociative<CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Key, T_Key, T_Key, CMultiset<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >,
  public NCommon::NIterators::IIteratorMoveBackward<CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>, T_Key, T_Key, CMultiset<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
  // Friend class: Multiset class (CMultiset).
  friend class CMultiset<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>;

  //! Type for MConceptAssociative constraint checking.
  typedef T_AssociativeContainer<T_Key, T_KeyBinaryPredicate, T_Allocator> TAssociativeCheckType;
  //! Type for MConceptAssociativeConst constraint checking.
  typedef T_AssociativeContainer<T_Key, T_KeyBinaryPredicate, T_Allocator> TAssociativeConstCheckType;
  //! Type for MConceptPredicate2 argument constraint checking.
  typedef const T_Key& TKeyPredicate2ArgumentCheckType;
  //! Type for MConceptPredicate2 constraint checking.
  typedef T_KeyBinaryPredicate TKeyPredicate2CheckType;
  //! Type for MConceptIAllocator constraint checking.
  typedef T_Allocator TAllocatorCheckType;
  //! Type for MConceptDepthType constraint checking.
  typedef CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> TDepthCheckType;

  // Check T_AssociativeContainer template argument constraint to be a non constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociative, TAssociativeCheckType);
  // Check T_AssociativeContainer template argument constraint to be a constant associative container type.
  REQUIRES_CONCEPT1(NConcept::NContainers, MConceptAssociativeConst, TAssociativeConstCheckType);
  // Check T_KeyBinaryPredicate template argument constraint to be a suitable binary predicate.
  REQUIRES_CONCEPT3(NConcept::NFunctions, MConceptPredicate2, TKeyPredicate2CheckType, TKeyPredicate2ArgumentCheckType, TKeyPredicate2ArgumentCheckType);
  // Check T_Allocator template argument constraint to be a memory allocator.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptIAllocator, TAllocatorCheckType);
  // Check CMultisetIteratorConst class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator associative key type.
  typedef T_Key TKey;
  //! Iterator associative value type.
  typedef T_Key TValue;

  //! Iterator value type.
  typedef T_Key TType;
  //! Iterator return type.
  typedef const T_Key TReturn;
  //! Iterator container type.
  typedef const CMultiset<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> TContainer;
  //! Iterator base type.
  typedef CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> TIterator;

  //! Container's key binary predicate type.
  typedef T_KeyBinaryPredicate TKeyLessThanPredicate;
  //! Base associative container type.
  typedef T_AssociativeContainer<T_Key, T_KeyBinaryPredicate, T_Allocator> TAssociativeContainer;
  //! Iterator allocator type.
  typedef T_Allocator TAllocator;

  //! Default class constructor.
  CMultisetIteratorConst();
  //! Initialize with non constant multiset iterator.
  /*!
      \param a_crInstance - Constant reference to the instance of the CMultisetIterator class.
  */
  CMultisetIteratorConst(const CMultisetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMultisetIteratorConst class.
  */
  CMultisetIteratorConst(const CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CMultisetIteratorConst();

  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CMultisetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CMultisetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CMultisetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CMultisetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator == (const CMultisetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CMultisetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CMultisetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CMultisetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the non constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CMultisetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CMultisetIterator<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend Tbool operator != (const CMultisetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance1, const CMultisetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance2);

  //! Operator: Assign another non constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the non constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator = (const CMultisetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);
  //! Operator: Assign another constant iterator class instance.
  /*!
      \param a_crInstance - Another instance of the constant iterator class.
      \return Reference to the current iterator class instance.
  */
  CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator = (const CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend CMultisetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator> operator + (const CMultisetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherKey, typename T_OtherKeyBinaryPredicate, template <typename, typename, class> class T_OtherAssociativeContainer, class T_OtherAllocator>
  friend CMultisetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator> operator - (const CMultisetIteratorConst<T_OtherKey, T_OtherKeyBinaryPredicate, T_OtherAssociativeContainer, T_OtherAllocator>& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Find iterator with given key in multiset.
  /*!
      \param a_crKey - Constant reference to the searching key.
      \return Iterator with given key or invalid empty iterator.
  */
  CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> operator [] (const T_Key& a_crKey) const;

  //! Set CMultisetIterator class instance.
  /*!
      \param a_crInstance - Constant reference to instance of the CMultisetIterator class.
  */
  void set(const CMultisetIterator<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);
  //! Set another CMultisetIteratorConst class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CMultisetIteratorConst class.
  */
  void set(const CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> getBackward() const;

  // IIteratorConst interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual const CMultiset<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& getContainerRef() const;
  virtual const CMultiset<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>* getContainerPtr() const;
  virtual const T_Key& getValueRef() const;
  virtual const T_Key* getValuePtr() const;

  // IIteratorMoveAssociative interface overriding methods.
  virtual CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> find(const T_Key& a_crKey) const;

  // IIteratorMoveBackward interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);

  //! Serialization load CMultisetIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool load(T_Archive& a_rArchive);
  //! Serialization save CMultisetIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool save(T_Archive& a_rArchive) const;
  //! Serialize CMultisetIteratorConst class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CMultisetIteratorConst class instances.
  /*!
      \param a_rInstance - Reference to another CMultisetIteratorConst class instance.
  */
  void swap(CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>& a_rInstance);

private:
  const CMultiset<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>* m_cpContainer;     //!< Constant pointer to the iterator container.
  typename T_AssociativeContainer<T_Key, T_KeyBinaryPredicate, T_Allocator>::TIteratorConst m_Iterator; //!< Base associative container constant iterator.

  //! Initialize iterator with the container value.
  /*!
      \param a_cpContainer - Constant pointer to the iterator container value.
  */
  CMultisetIteratorConst(const CMultiset<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>* a_cpContainer);
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
//! Traits meta-class: multiset constant iterator's traits specialization.
template <typename T_Key, typename T_KeyBinaryPredicate, template <typename, typename, class> class T_AssociativeContainer, class T_Allocator>
class MTraitsIterator<NContainers::NIterators::CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> > :
  public MType<NContainers::NIterators::CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CMultisetIteratorConst<T_Key, T_KeyBinaryPredicate, T_AssociativeContainer, T_Allocator>::TIterator iterator;

  static const Tbool isConst             = true;  //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = false; //!< Is iterator supports random moving?
  static const Tbool isMoveAssociative   = true;  //!< Is iterator supports associative moving?
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
#include <Depth/include/containers/iterators/CMultisetIteratorConst.inl>
/*==========================================================================*/
#endif
