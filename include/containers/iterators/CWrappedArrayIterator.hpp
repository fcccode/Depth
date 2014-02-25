/*!
 *  \file    CWrappedArrayIterator.hpp Wrapped array non constant iterator
 *           definitions. It gives ability to get and modify wrapped array
 *           items and to do random moving through the wrapped array items.
 *  \brief   Wrapped array non constant iterator class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Wrapped array non constant iterator class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   23.04.2007 22:15:32

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
#ifndef __CWRAPPEDARRAYITERATOR_HPP__
#define __CWRAPPEDARRAYITERATOR_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMin.hpp>
#include <Depth/include/common/ISeekable.hpp>
#include <Depth/include/common/iterators/IIterator.hpp>
#include <Depth/include/common/iterators/IIteratorMoveRandom.hpp>
#include <Depth/include/containers/CWrappedArray.hpp>
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
//! Wrapped array non constant iterator class.
/*!
    Wrapped array non constant iterator represents  wrapped  array  iterations
    method. With this iterator you can perform  random  moving  and  modifying
    wrapped array items.
*/
template <typename T_Type>
class CWrappedArrayIterator :
  public NCommon::NIterators::IIterator<CWrappedArrayIterator<T_Type>, T_Type, T_Type, CWrappedArray<T_Type> >,
  public NCommon::NIterators::IIteratorMoveRandom<CWrappedArrayIterator<T_Type>, T_Type, T_Type, CWrappedArray<T_Type> >,
  public NCommon::ISeekable
{
  // Friend class: Wrapped array class (CWrappedArray).
  friend class CWrappedArray<T_Type>;
  // Friend class: Wrapped array constant iterator class (CWrappedArrayIteratorConst).
  friend class CWrappedArrayIteratorConst<T_Type>;

  //! Type for MConceptDepthType constraint checking.
  typedef CWrappedArrayIterator<T_Type> TDepthCheckType;

  // Check CWrappedArrayIterator class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Iterator value type.
  typedef T_Type TType;
  //! Iterator return type.
  typedef T_Type TReturn;
  //! Iterator container type.
  typedef CWrappedArray<T_Type> TContainer;
  //! Iterator base type.
  typedef CWrappedArrayIterator<T_Type> TIterator;

  //! Default class constructor.
  CWrappedArrayIterator();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CWrappedArrayIterator class.
  */
  CWrappedArrayIterator(const CWrappedArrayIterator<T_Type>& a_crInstance);
  //! Class virtual destructor.
  virtual ~CWrappedArrayIterator();

  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const CWrappedArrayIterator<T_OtherType>& a_crInstance1, const CWrappedArrayIteratorConst<T_OtherType>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const CWrappedArrayIteratorConst<T_OtherType>& a_crInstance1, const CWrappedArrayIterator<T_OtherType>& a_crInstance2);
  //! Operator: Equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are equal. \n
              false - if class instances are not equal. \n
  */
  template <typename T_OtherType>
  friend Tbool operator == (const CWrappedArrayIterator<T_OtherType>& a_crInstance1, const CWrappedArrayIterator<T_OtherType>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const CWrappedArrayIterator<T_OtherType>& a_crInstance1, const CWrappedArrayIteratorConst<T_OtherType>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const CWrappedArrayIteratorConst<T_OtherType>& a_crInstance1, const CWrappedArrayIterator<T_OtherType>& a_crInstance2);
  //! Operator: Not equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if class instances are not equal. \n
              false - if class instances are equal. \n
  */
  template <typename T_OtherType>
  friend Tbool operator != (const CWrappedArrayIterator<T_OtherType>& a_crInstance1, const CWrappedArrayIterator<T_OtherType>& a_crInstance2);

  //! Operator: Less than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator < (const CWrappedArrayIterator<T_OtherType>& a_crInstance1, const CWrappedArrayIteratorConst<T_OtherType>& a_crInstance2);
  //! Operator: Less than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator < (const CWrappedArrayIteratorConst<T_OtherType>& a_crInstance1, const CWrappedArrayIterator<T_OtherType>& a_crInstance2);
  //! Operator: Less than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less than given one. \n
              false - if current iterator is not less than given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator < (const CWrappedArrayIterator<T_OtherType>& a_crInstance1, const CWrappedArrayIterator<T_OtherType>& a_crInstance2);
  //! Operator: More than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator > (const CWrappedArrayIterator<T_OtherType>& a_crInstance1, const CWrappedArrayIteratorConst<T_OtherType>& a_crInstance2);
  //! Operator: More than another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator > (const CWrappedArrayIteratorConst<T_OtherType>& a_crInstance1, const CWrappedArrayIterator<T_OtherType>& a_crInstance2);
  //! Operator: More than another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more than given one. \n
              false - if current iterator is not more than given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator > (const CWrappedArrayIterator<T_OtherType>& a_crInstance1, const CWrappedArrayIterator<T_OtherType>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator <= (const CWrappedArrayIterator<T_OtherType>& a_crInstance1, const CWrappedArrayIteratorConst<T_OtherType>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator <= (const CWrappedArrayIteratorConst<T_OtherType>& a_crInstance1, const CWrappedArrayIterator<T_OtherType>& a_crInstance2);
  //! Operator: Less or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is less or equal to the given one. \n
              false - if current iterator is not less or equal to the given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator <= (const CWrappedArrayIterator<T_OtherType>& a_crInstance1, const CWrappedArrayIterator<T_OtherType>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator >= (const CWrappedArrayIterator<T_OtherType>& a_crInstance1, const CWrappedArrayIteratorConst<T_OtherType>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the constant type.
  /*!
      \param a_crInstance1 - Another instance of the iterator class.
      \param a_crInstance2 - Current instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator >= (const CWrappedArrayIteratorConst<T_OtherType>& a_crInstance1, const CWrappedArrayIterator<T_OtherType>& a_crInstance2);
  //! Operator: More or equal to another iterator instance with the same type.
  /*!
      \param a_crInstance1 - Current instance of the iterator class.
      \param a_crInstance2 - Another instance of the iterator class.
      \return true  - if current iterator is more or equal to the given one. \n
              false - if current iterator is not or equal to the given one. \n
  */
  template <typename T_OtherType>
  friend Tbool operator >= (const CWrappedArrayIterator<T_OtherType>& a_crInstance1, const CWrappedArrayIterator<T_OtherType>& a_crInstance2);

  //! Operator: Assign another iterator class instance.
  /*!
      \param a_crInstance - Another instance of the iterator class.
      \return Reference to the current iterator class instance.
  */
  CWrappedArrayIterator<T_Type>& operator = (const CWrappedArrayIterator<T_Type>& a_crInstance);

  //! Operator: Step forward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CWrappedArrayIterator<T_Type>& operator += (const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_cStepCount - Steps count to iteration.
      \return Reference to the current class instance.
  */
  CWrappedArrayIterator<T_Type>& operator -= (const Tuint a_cStepCount);
  //! Operator: Step forward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CWrappedArrayIterator<T_Type>& operator ++ ();
  //! Operator: Step backward once. Prefix version.
  /*!
      \return Reference to the current class instance.
  */
  CWrappedArrayIterator<T_Type>& operator -- ();
  //! Operator: Step forward once. Postfix version.
  /*!
      \return New class instance.
  */
  CWrappedArrayIterator<T_Type> operator ++ (int);
  //! Operator: Step backward once. Postfix version.
  /*!
      \return New class instance.
  */
  CWrappedArrayIterator<T_Type> operator -- (int);

  //! Operator: Step forward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType>
  friend CWrappedArrayIterator<T_OtherType> operator + (const CWrappedArrayIterator<T_OtherType>& a_crInstance, const Tuint a_cStepCount);
  //! Operator: Step backward by given steps.
  /*!
      \param a_crInstance - Current instance of the iterator class.
      \param a_cStepCount - Steps count to iteration.
      \return New class instance.
  */
  template <typename T_OtherType>
  friend CWrappedArrayIterator<T_OtherType> operator - (const CWrappedArrayIterator<T_OtherType>& a_crInstance, const Tuint a_cStepCount);

  //! Operator: Get new wrapped array's non constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed wrapped array position to return.
      \return Wrapped array's non constant iterator under the given index.
  */
  CWrappedArrayIterator<T_Type> operator [] (const Tsint a_cIndex) const;
  //! Operator: Get new wrapped array's non constant iterator under the given index.
  /*!
      \param a_cIndex - Indexed wrapped array position to return.
      \return Wrapped array's non constant iterator under the given index.
  */
  CWrappedArrayIterator<T_Type> operator [] (const Tuint a_cIndex) const;

  //! Set another CWrappedArrayIterator class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CWrappedArrayIterator class.
  */
  void set(const CWrappedArrayIterator<T_Type>& a_crInstance);

  //! Get forward iterator.
  /*!
      Method  uses 'stepForward()' iterator method to get a  forward  iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Forward iterator.
  */
  CWrappedArrayIterator<T_Type> getForward() const;
  //! Get backward iterator.
  /*!
      Method  uses 'stepBackward()' iterator method to get a backward iterator
      instance. If forward iteration cannot be  done  method  returns  invalid
      iterator.

      \return Backward iterator.
  */
  CWrappedArrayIterator<T_Type> getBackward() const;
  //! Get indexed iterator.
  /*!
      Method uses 'stepIndex()' iterator method to  get  an  indexed  iterator
      instance. If indexed iteration cannot be  done  method  returns  invalid
      iterator.

      \param a_cIndex - Indexed iterator position to return.
      \return Random iterator under the given index.
  */
  CWrappedArrayIterator<T_Type> getIndex(const Tuint a_cIndex) const;

  // IIterator interface overriding methods.
  virtual Tbool isValid() const;
  virtual Tbool isValidContainer() const;
  virtual CWrappedArray<T_Type>& getContainerRef() const;
  virtual CWrappedArray<T_Type>* getContainerPtr() const;
  virtual T_Type& getValueRef() const;
  virtual T_Type* getValuePtr() const;

  // IIteratorMoveRandom interface overriding methods.
  virtual Tuint stepForward(const Tuint a_cStepCount = 1);
  virtual Tuint stepBackward(const Tuint a_cStepCount = 1);
  virtual Tbool stepIndex(const Tuint a_cIndex);

  // ISeekable interface overriding methods.
  virtual Tuint getSize() const;
  virtual Tbool setPosition(const Tuint a_cPosition);
  virtual Tuint getPosition() const;

  //! Serialize CWrappedArrayIterator class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CWrappedArrayIterator class instances.
  /*!
      \param a_rInstance - Reference to another CWrappedArrayIterator class instance.
  */
  void swap(CWrappedArrayIterator<T_Type>& a_rInstance);

private:
  CWrappedArray<T_Type>* m_pContainer;  //!< Pointer to the iterator container.
  Tuint m_Index;                        //!< Index of the current wrapped array item.

  //! Initialize iterator with the container value.
  /*!
      \param a_pContainer - Pointer to the iterator container value.
  */
  CWrappedArrayIterator(CWrappedArray<T_Type>* a_pContainer);
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
//! Traits meta-class: wrapped array non constant iterator's traits specialization.
template <typename T_Type>
class MTraitsIterator<NContainers::NIterators::CWrappedArrayIterator<T_Type> > :
  public MType<NContainers::NIterators::CWrappedArrayIterator<T_Type> >
{
public:
  //! Iterator value type.
  typedef typename NContainers::NIterators::CWrappedArrayIterator<T_Type>::TType value;
  //! Iterator return type.
  typedef typename NContainers::NIterators::CWrappedArrayIterator<T_Type>::TReturn result;
  //! Iterator container type.
  typedef typename NContainers::NIterators::CWrappedArrayIterator<T_Type>::TContainer container;
  //! Iterator base type.
  typedef typename NContainers::NIterators::CWrappedArrayIterator<T_Type>::TIterator iterator;

  static const Tbool isConst             = false; //!< Is iterator constant?
  static const Tbool isCircled           = false; //!< Is iterator container circled?
  static const Tbool isMoveForward       = true;  //!< Is iterator supports forward moving?
  static const Tbool isMoveBackward      = true;  //!< Is iterator supports forward and backward moving?
  static const Tbool isMoveRandom        = true;  //!< Is iterator supports random moving?
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
#include <Depth/include/containers/iterators/CWrappedArrayIterator.inl>
/*==========================================================================*/
#endif
