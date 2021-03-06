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



#include "CCLifetimeVG.h"


namespace soomla {

    USING_NS_CC;

    CCLifetimeVG *CCLifetimeVG::create(__String *name, __String *description, __String *itemId, CCPurchaseType *purchaseType) {
        CCLifetimeVG *ret = new CCLifetimeVG();
        if (ret->init(name, description, itemId, purchaseType)) {
            ret->autorelease();
        }
        else {
            CC_SAFE_DELETE(ret);
        }

        return ret;
    }

    const char *CCLifetimeVG::getType() const {
        return CCStoreConsts::JSON_JSON_TYPE_LIFETIME_VG;
    }
}
