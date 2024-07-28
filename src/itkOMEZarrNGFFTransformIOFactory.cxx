/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         https://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#include "itkOMEZarrNGFFTransformIOFactory.h"
#include "itkOMEZarrNGFFTransformIO.h"
#include "itkVersion.h"

namespace itk
{
OMEZarrNGFFTransformIOFactory::OMEZarrNGFFTransformIOFactory()
{
  this->RegisterOverride("itkTransformIOBaseTemplate",
                         "itkOMEZarrNGFFTransformIOTemplate",
                         "OMEZarrNGFF Transform float IO",
                         true,
                         CreateObjectFunction<OMEZarrNGFFTransformIOTemplate<float>>::New());

  this->RegisterOverride("itkTransformIOBaseTemplate",
                         "itkOMEZarrNGFFTransformIOTemplate",
                         "OMEZarrNGFF Transform double IO",
                         true,
                         CreateObjectFunction<OMEZarrNGFFTransformIOTemplate<double>>::New());
}

const char *
OMEZarrNGFFTransformIOFactory::GetITKSourceVersion() const
{
  return ITK_SOURCE_VERSION;
}

const char *
OMEZarrNGFFTransformIOFactory::GetDescription() const
{
  return "OMEZarrNGFF TransformIO Factory, allows the loading of images in Open Microscopy Environment Zarr Next Generation File Format";
}

// Undocumented API used to register during static initialization.
// DO NOT CALL DIRECTLY.

static bool OMEZarrNGFFTransformIOFactoryHasBeenRegistered;

void IOOMEZarrNGFF_EXPORT
OMEZarrNGFFTransformIOFactoryRegister__Private()
{
  if (!OMEZarrNGFFTransformIOFactoryHasBeenRegistered)
  {
    OMEZarrNGFFTransformIOFactoryHasBeenRegistered = true;
    OMEZarrNGFFTransformIOFactory::RegisterOneFactory();
  }
}

} // end namespace itk