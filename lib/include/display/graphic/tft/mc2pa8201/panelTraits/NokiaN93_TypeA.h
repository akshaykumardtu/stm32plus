/*
 * This file is a part of the open source stm32plus library.
 * Copyright (c) 2011,2012,2013,2014 Andy Brown <www.andybrown.me.uk>
 * Please see website for licensing terms.
 */

#pragma once


namespace stm32plus {
  namespace display {

    /**
     * Panel traits for a Type A Nokia N93 panel
     *
     * 1. Positive scroll offsets scroll downwards
     * 3. RGB is the only transfer order supported
     */

    class NokiaN93_TypeA {
      public:
        static int16_t normaliseScrollPosition(int16_t scrollPosition);

        template<Orientation TOrientation>
        constexpr static uint8_t getColumnAddressCommand();

        template<Orientation TOrientation>
        constexpr static uint8_t getPageAddressCommand();

        template<Orientation TOrientation>
        constexpr static uint8_t getMemoryAccessControlCommand();

        constexpr static uint16_t getScrollHeight();
    };


    /**
     * Get the maximum scroll height on this display
     * @return 320px
     */

    constexpr inline uint16_t NokiaN93_TypeA::getScrollHeight() {
      return 320;
    }


    /**
     * Normalise the scroll position for the setScrollPosition() call
     * @param scrollPosition the raw scroll position (0..320)
     * @return the normalised position - adjusted if necessary
     */

    inline int16_t NokiaN93_TypeA::normaliseScrollPosition(int16_t scrollPosition) {
      return scrollPosition ? 320-scrollPosition : 0;
    }


    /**
     * Get the command used to set column address in landscape mode
     * @return mc2pa8201::PAGE_ADDRESS_SET
     */

    template<>
    constexpr inline uint8_t NokiaN93_TypeA::getColumnAddressCommand<LANDSCAPE>() {
      return mc2pa8201::COLUMN_ADDRESS_SET;
    }


    /**
     * Get the command used to set column address in landscape mode
     * @return mc2pa8201::COLUMN_ADDRESS_SET
     */

    template<>
    constexpr inline uint8_t NokiaN93_TypeA::getPageAddressCommand<LANDSCAPE>() {
      return mc2pa8201::PAGE_ADDRESS_SET;
    }


    /**
     * Get the command used to set the orientation
     * @return 0xa0
     */

    template<>
    constexpr inline uint8_t NokiaN93_TypeA::getMemoryAccessControlCommand<LANDSCAPE>() {
      return 0xa0;
    }


    /**
     * Get the command used to set the orientation
     * @return 0xa0
     */

    template<>
    constexpr inline uint8_t NokiaN93_TypeA::getMemoryAccessControlCommand<PORTRAIT>() {
      return 0xc0;
    }
  }
}
