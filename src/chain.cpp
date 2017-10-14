// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chain.h"

uint256 CBlockIndex::GetBlockTrust() const
{
    uint256 bnTarget;
    bnTarget.SetCompact(nBits);

    if (bnTarget == 0)
        return 0;

	// We need to compute 2**256 / (bnTarget+1), but we can't represent 2**256
	// as it's too large for a uint256. However, as 2**256 is at least as large
	// as bnTarget+1, it is equal to ((2**256 - bnTarget - 1) / (bnTarget+1)) + 1,
	// or ~bnTarget / (nTarget+1) + 1.

    return (~bnTarget / (bnTarget + 1)) + 1;
}
