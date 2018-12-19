/**
 * @file r8bsrc.cpp
 *
 * @brief The "r8bsrc.dll" source file.
 *
 * r8brain-free-src Copyright (c) 2013-2018 Aleksey Vaneev
 * See the "License.txt" file for license.
 */

#include "r8bsrc.h"
#include "../CDSPResampler.h"
using namespace r8b;

CR8BResampler r8b_create(double SrcSampleRate,
                         double DstSampleRate, int MaxInLen, double ReqTransBand,
                         ER8BResamplerRes Res)
{
    if (Res == r8brr16)
    {
        return new CDSPResampler16(SrcSampleRate, DstSampleRate, MaxInLen, ReqTransBand);
    }

    if (Res == r8brr16IR)
    {
        return new CDSPResampler16IR(SrcSampleRate, DstSampleRate, MaxInLen, ReqTransBand));
    }

    return new CDSPResampler24(SrcSampleRate, DstSampleRate, MaxInLen, ReqTransBand));
}

void r8b_delete(CR8BResampler const rs)
{
    delete (CDSPProcessor *)rs;
}

void r8b_clear(CR8BResampler const rs)
{
    ((CDSPProcessor *)rs)->clear();
}

int r8b_process(CR8BResampler const rs, double *const ip0, int l, double *&op0)
{
    return ((CDSPProcessor *)rs)->process(ip0, l, op0);
}
