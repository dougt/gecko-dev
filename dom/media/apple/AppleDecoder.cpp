/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "AppleDecoder.h"
#include "AppleMP3Reader.h"

#include "MediaDecoderStateMachine.h"

namespace mozilla {

AppleDecoder::AppleDecoder(MediaDecoderOwner* aOwner)
  : MediaDecoder(aOwner)
{
}

MediaDecoder *
AppleDecoder::Clone(MediaDecoderOwner* aOwner)
{
  return new AppleDecoder(aOwner);
}

MediaDecoderStateMachine *
AppleDecoder::CreateStateMachine()
{
  // TODO MP4
  return new MediaDecoderStateMachine(this, new AppleMP3Reader(this));
}

} // namespace mozilla
