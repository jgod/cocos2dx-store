/*
 Copyright (C) 2012-2014 Soomla Inc.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */



#include "CCVirtualCurrencyPack.h"

USING_NS_CC;

namespace soomla {
    CCVirtualCurrencyPack *CCVirtualCurrencyPack::create(__String *name, __String *description, __String *itemId, __Integer *currencyAmount, __String *currencyItemId, CCPurchaseType *purchaseType) {
        CCVirtualCurrencyPack *ret = new CCVirtualCurrencyPack();
        if (ret->init(name, description, itemId, currencyAmount, currencyItemId, purchaseType)) {
            ret->autorelease();
        }
        else {
            CC_SAFE_DELETE(ret);
        }
        return ret;
    }

    bool CCVirtualCurrencyPack::init(__String *name, __String *description, __String *itemId, __Integer *currencyAmount, __String *currencyItemId, CCPurchaseType *purchaseType) {
        bool res = CCPurchasableVirtualItem::init(name, description, itemId, purchaseType);
        if (res) {
            setCurrencyAmount(currencyAmount);
            setCurrencyItemId(currencyItemId);
            return true;
        } else {
            return false;
        }
    }

    bool CCVirtualCurrencyPack::initWithDictionary(__Dictionary *dict) {
        bool res = CCPurchasableVirtualItem::initWithDictionary(dict);
        if (res) {
            fillCurrencyAmountFromDict(dict);
            fillCurrencyItemIdFromDict(dict);

            return true;
        } else {
            return false;
        }
    }

    __Dictionary *CCVirtualCurrencyPack::toDictionary() {
        __Dictionary *dict = CCPurchasableVirtualItem::toDictionary();

        putCurrencyAmountToDict(dict);
        putCurrencyItemIdToDict(dict);

        return dict;
    }


    const char *CCVirtualCurrencyPack::getType() const {
        return CCStoreConsts::JSON_JSON_TYPE_VIRTUAL_CURRENCY_PACK;
    }

    CCVirtualCurrencyPack::~CCVirtualCurrencyPack() {
        CC_SAFE_RELEASE(mCurrencyAmount);
        CC_SAFE_RELEASE(mCurrencyItemId);
    }
}    
