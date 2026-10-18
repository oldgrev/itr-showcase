#include "PRCleanTransform.h"

#include "ITRDefaults.h"
FPRCleanTransform::FPRCleanTransform() {
    ITRDefaults::Set(StaticStruct(), this, TEXT("Location.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Location.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Location.Z"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Rotation.X"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Rotation.Y"), (double)0);
    ITRDefaults::Set(StaticStruct(), this, TEXT("Rotation.Z"), (double)0);
}
