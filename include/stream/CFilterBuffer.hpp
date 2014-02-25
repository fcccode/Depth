/*!
 *  \file    CFilterBuffer.hpp Buffer filter class accumulates data from
 *           another stream/filter in the dynamic or static buffer until
 *           flush is not called.
 *  \brief   Buffer filter class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Buffer filter class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream
    VERSION:   1.0
    CREATED:   20.03.2009 21:38:33

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
#ifndef __CFILTERBUFFER_HPP__
#define __CFILTERBUFFER_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/stream/IFilter.hpp>
#include <Depth/include/utility/CBuffer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Buffer filter.
/*!
    Buffer filter class accumulates data from  another  stream/filter  in  the
    dynamic or static buffer until flush is not called.
*/
class BASE_API CFilterBuffer :
  public IFilter
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CFilterBuffer TDepthCheckType;

  // Check CFilterBuffer class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Create disconnected filter.
  /*!
      \param a_cSize - Initial size of the buffer in bytes (default is 0).
      \param a_cStatic - Static buffer flag (default is false).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBuffer(const Tuint a_cSize = 0, const Tbool a_cStatic = false, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_cSize - Initial size of the buffer in bytes (default is 0).
      \param a_cStatic - Static buffer flag (default is false).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBuffer(IReader* a_pReader, const Tuint a_cSize = 0, const Tbool a_cStatic = false, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given writer.
  /*!
      \param a_pWriter - Pointer to the writer interface.
      \param a_cSize - Initial size of the buffer in bytes (default is 0).
      \param a_cStatic - Static buffer flag (default is false).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBuffer(IWriter* a_pWriter, const Tuint a_cSize = 0, const Tbool a_cStatic = false, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given reader & writer.
  /*!
      \param a_pReaderWriter - Pointer to the reader & writer interface.
      \param a_cSize - Initial size of the buffer in bytes (default is 0).
      \param a_cStatic - Static buffer flag (default is false).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBuffer(IReaderWriter* a_pReaderWriter, const Tuint a_cSize = 0, const Tbool a_cStatic = false, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Create filter which is connected to the given separate reader and writer.
  /*!
      \param a_pReader - Pointer to the reader interface.
      \param a_pWriter - Pointer to the writer interface.
      \param a_cSize - Initial size of the buffer in bytes (default is 0).
      \param a_cStatic - Static buffer flag (default is false).
      \param a_cTextMode - Text mode flag (default is false).
      \param a_cByteOrder - Byte order type (default is NDepth::NStream::IStream::e_BYTE_ORDER_UNIVERSAL).
      \param a_cLineEnding - Line ending type (default is NDepth::NStream::IStream::e_LINE_ENDING_UNIVERSAL).
  */
  CFilterBuffer(IReader* a_pReader, IWriter* a_pWriter, const Tuint a_cSize = 0, const Tbool a_cStatic = false, const Tbool a_cTextMode = false, const EByteOrder a_cByteOrder = IStream::e_BYTE_ORDER_UNIVERSAL, const ELineEnding a_cLineEnding = IStream::e_LINE_ENDING_UNIVERSAL);
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterCopy class.
  */
  CFilterBuffer(const CFilterBuffer& a_crInstance);
  //! Class virtual destructor.
  virtual ~CFilterBuffer();

  //! Operator: Assign another CFilterBuffer class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterBuffer class.
      \return Reference to the current class instance.
  */
  CFilterBuffer& operator = (const CFilterBuffer& a_crInstance);

  //! Set another CFilterBuffer class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CFilterBuffer class.
      \return true  - if another filter was successfully set. \n
              false - if another filter was not successfully set. \n
  */
  Tbool set(const CFilterBuffer& a_crInstance);

  //! Set read buffer parameters.
  /*!
      \param a_cSize - Initial size of the buffer in bytes.
      \param a_cStatic - Static buffer flag.
      \return true  - if read buffer parameters were successfully set. \n
              false - if read buffer parameters were not successfully set. \n
  */
  Tbool setReadBuffer(const Tuint a_cSize, const Tbool a_cStatic);
  //! Set write buffer parameters.
  /*!
      \param a_cSize - Initial size of the buffer in bytes.
      \param a_cStatic - Static buffer flag.
      \return true  - if write buffer parameters were successfully set. \n
              false - if write buffer parameters were not successfully set. \n
  */
  Tbool setWriteBuffer(const Tuint a_cSize, const Tbool a_cStatic);

  //! Serialize CFilterBuffer class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CFilterBuffer class instances.
  /*!
      \param a_rInstance - Reference to another CFilterBuffer class instance.
  */
  void swap(CFilterBuffer& a_rInstance);

protected:
  NUtility::CBuffer m_ReadBuffer;       //!< Read buffer.
  Tuint             m_ReadBufferIndex;  //!< Read buffer index.
  Tuint             m_ReadBufferSize;   //!< Read buffer size.
  Tuint             m_ReadBufferType;   //!< Read buffer type (binary, ASCII or Unicode).

  NUtility::CBuffer m_WriteBuffer;      //!< Write buffer.
  Tuint             m_WriteBufferIndex; //!< Write buffer index.
  Tuint             m_WriteBufferSize;  //!< Write buffer size.
  Tuint             m_WriteBufferType;  //!< Write buffer type (binary, ASCII or Unicode).

  // IReaderWriter interface overriding methods.
  virtual Tbool onOpen(const EOpenType a_cOpenType);
  virtual Tbool onFlush();
  virtual Tbool onClose();

  // IFilter interface overriding methods.
  virtual Tuint onFilterReadBinary(IReader& a_rReader, Tptr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterReadText(IReader& a_rReader, Tsstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterReadText(IReader& a_rReader, Twstr a_pBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteBinary(IWriter& a_rWriter, Tcptr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteText(IWriter& a_rWriter, Tcsstr a_cpBuffer, const Tuint a_cSize);
  virtual Tuint onFilterWriteText(IWriter& a_rWriter, Tcwstr a_cpBuffer, const Tuint a_cSize);

  //! Fill read buffer.
  /*!
      Method is used to fill read buffer from the connected  stream.  If  read
      buffer is static it it will be filled with its size. If read  buffer  is
      dynamic it will be filled with separate chunks until we  can  read  from
      the connected stream.

      \param a_cChunkSize - Chunk size in bytes (default is 1024).
      \return true  - if read buffer was successfully filled. \n
              false - if read buffer was not successfully filled. \n
  */
  Tbool fillReadBuffer(const Tuint a_cChunkSize = 1024);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/CFilterBuffer.inl>
/*==========================================================================*/
//! \example example-stream-CFilterBuffer.cpp
/*--------------------------------------------------------------------------*/
//! \test test-stream-CFilterBuffer.cpp
/*==========================================================================*/
#endif
