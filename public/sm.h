#ifndef SHADOW_MAPPING_SM_H
#define SHADOW_MAPPING_SM_H

#include "IRenderer.h"

typedef IRenderer* (*GetRendererFn_t)(void);
#define GETRENDERERFN_SYMBOL "GetRenderer"

#endif /* SHADOW_MAPPING_SM_H */
