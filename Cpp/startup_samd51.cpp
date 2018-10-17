/*******************************************************************************
*  FILENAME: startup_samd51.cpp
*  Author: YZagoskin
*******************************************************************************/
#pragma language = extended
#pragma segment = "CSTACK"

extern "C" void __iar_program_start(void);
extern "C" int __low_level_init(void);

class dummyHandler
{
public:
      static void handler(void);
  
};

typedef void (*intfunc) (void);
typedef union { intfunc __fun; void * __ptr; } intvec_elem;

/* Exception Table */
#pragma language = extended
#pragma segment  = "CSTACK"

/* The name "__vector_table" has special meaning for C-SPY: */
/* it is where the SP start value is found, and the NVIC vector */
/* table register (VTOR) is initialized to this address if != 0 */

#pragma section  = ".intvec"
#pragma location = ".intvec"
extern "C" const intvec_elem __vector_table[] =
{
  { .__ptr = __sfe( "CSTACK" ) }, 
  __iar_program_start,            
    dummyHandler::handler,                 
    dummyHandler::handler,         
    dummyHandler::handler,       
    dummyHandler::handler,           
    dummyHandler::handler,      
        0,                    
        0,                    
        0,                        
        0,                        
    dummyHandler::handler,              
    dummyHandler::handler,           
        0,                        
        dummyHandler::handler,           
        dummyHandler::handler,          
    /* Configurable interrupts */
    dummyHandler::handler,         /*  0 Power Manager */
    dummyHandler::handler,       /*  1 Main Clock */
    dummyHandler::handler,  /*  2 OSCCTRL_XOSCFAIL_0, OSCCTRL_XOSCRDY_0 */
    dummyHandler::handler,  /*  3 OSCCTRL_XOSCFAIL_1, OSCCTRL_XOSCRDY_1 */
    dummyHandler::handler,  /*  4 OSCCTRL_DFLLLOCKC, OSCCTRL_DFLLLOCKF, OSCCTRL_DFLLOOB, OSCCTRL_DFLLRCS,
                                   OSCCTRL_DFLLRDY */
    dummyHandler::handler,  /*  5 OSCCTRL_DPLLLCKF_0, OSCCTRL_DPLLLCKR_0, OSCCTRL_DPLLLDRTO_0, OSCCTRL_DPLLLTO_0 */
    dummyHandler::handler,  /*  6 OSCCTRL_DPLLLCKF_1, OSCCTRL_DPLLLCKR_1, OSCCTRL_DPLLLDRTO_1, OSCCTRL_DPLLLTO_1 */
    dummyHandler::handler, /*  7 32kHz Oscillators Control */
    
    dummyHandler::handler, /*  8 SUPC_B12SRDY, SUPC_B33SRDY, SUPC_BOD12RDY, SUPC_BOD33RDY, SUPC_VCORERDY, SUPC_VREGRDY */
    dummyHandler::handler,    /*  9 SUPC_BOD12DET, SUPC_BOD33DET */
    dummyHandler::handler,       /* 10 Watchdog Timer */
    dummyHandler::handler,       /* 11 Real-Time Counter */
    dummyHandler::handler,     /* 12 EIC_EXTINT_0 */
    dummyHandler::handler,     /* 13 EIC_EXTINT_1 */
    dummyHandler::handler,     /* 14 EIC_EXTINT_2 */
    dummyHandler::handler,     /* 15 EIC_EXTINT_3 */
    dummyHandler::handler,     /* 16 EIC_EXTINT_4 */
    dummyHandler::handler,     /* 17 EIC_EXTINT_5 */
    dummyHandler::handler,     /* 18 EIC_EXTINT_6 */
    dummyHandler::handler,     /* 19 EIC_EXTINT_7 */
    dummyHandler::handler,     /* 20 EIC_EXTINT_8 */
    dummyHandler::handler,     /* 21 EIC_EXTINT_9 */
    dummyHandler::handler,    /* 22 EIC_EXTINT_10 */
    dummyHandler::handler,    /* 23 EIC_EXTINT_11 */
    dummyHandler::handler,    /* 24 EIC_EXTINT_12 */
    dummyHandler::handler,    /* 25 EIC_EXTINT_13 */
    dummyHandler::handler,    /* 26 EIC_EXTINT_14 */
    dummyHandler::handler,    /* 27 EIC_EXTINT_15 */
    dummyHandler::handler,     /* 28 Frequency Meter */
    dummyHandler::handler, /* 29 NVMCTRL_0, NVMCTRL_1, NVMCTRL_2, NVMCTRL_3, NVMCTRL_4, NVMCTRL_5, NVMCTRL_6,
                                  NVMCTRL_7 */
    dummyHandler::handler, /* 30 NVMCTRL_10, NVMCTRL_8, NVMCTRL_9 */
    dummyHandler::handler,    /* 31 DMAC_SUSP_0, DMAC_TCMPL_0, DMAC_TERR_0 */
    dummyHandler::handler,    /* 32 DMAC_SUSP_1, DMAC_TCMPL_1, DMAC_TERR_1 */
    dummyHandler::handler,    /* 33 DMAC_SUSP_2, DMAC_TCMPL_2, DMAC_TERR_2 */
    dummyHandler::handler,    /* 34 DMAC_SUSP_3, DMAC_TCMPL_3, DMAC_TERR_3 */
    
    dummyHandler::handler,        /* 35 DMAC_SUSP_10, DMAC_SUSP_11, DMAC_SUSP_12, DMAC_SUSP_13, DMAC_SUSP_14, DMAC_SUSP_15,
                                  DMAC_SUSP_16, DMAC_SUSP_17, DMAC_SUSP_18, DMAC_SUSP_19, DMAC_SUSP_20, DMAC_SUSP_21,
                                  DMAC_SUSP_22, DMAC_SUSP_23, DMAC_SUSP_24, DMAC_SUSP_25, DMAC_SUSP_26, DMAC_SUSP_27,
                                  DMAC_SUSP_28, DMAC_SUSP_29, DMAC_SUSP_30, DMAC_SUSP_31, DMAC_SUSP_4, DMAC_SUSP_5,
                                  DMAC_SUSP_6, DMAC_SUSP_7, DMAC_SUSP_8, DMAC_SUSP_9, DMAC_TCMPL_10, DMAC_TCMPL_11,
                                  DMAC_TCMPL_12, DMAC_TCMPL_13, DMAC_TCMPL_14, DMAC_TCMPL_15, DMAC_TCMPL_16, DMAC_TCMPL_17,
                                  DMAC_TCMPL_18, DMAC_TCMPL_19, DMAC_TCMPL_20, DMAC_TCMPL_21, DMAC_TCMPL_22, DMAC_TCMPL_23,
                                  DMAC_TCMPL_24, DMAC_TCMPL_25, DMAC_TCMPL_26, DMAC_TCMPL_27, DMAC_TCMPL_28, DMAC_TCMPL_29,
                                  DMAC_TCMPL_30, DMAC_TCMPL_31, DMAC_TCMPL_4, DMAC_TCMPL_5, DMAC_TCMPL_6, DMAC_TCMPL_7,
                                  DMAC_TCMPL_8, DMAC_TCMPL_9, DMAC_TERR_10, DMAC_TERR_11, DMAC_TERR_12, DMAC_TERR_13,
                                  DMAC_TERR_14, DMAC_TERR_15, DMAC_TERR_16, DMAC_TERR_17, DMAC_TERR_18, DMAC_TERR_19,
                                  DMAC_TERR_20, DMAC_TERR_21, DMAC_TERR_22, DMAC_TERR_23, DMAC_TERR_24, DMAC_TERR_25,
                                  DMAC_TERR_26, DMAC_TERR_27, DMAC_TERR_28, DMAC_TERR_29, DMAC_TERR_30, DMAC_TERR_31,
                                  DMAC_TERR_4, DMAC_TERR_5, DMAC_TERR_6, DMAC_TERR_7, DMAC_TERR_8, DMAC_TERR_9 */
    dummyHandler::handler,   /* 36 EVSYS_EVD_0, EVSYS_OVR_0 */
    dummyHandler::handler,   /* 37 EVSYS_EVD_1, EVSYS_OVR_1 */
    dummyHandler::handler,   /* 38 EVSYS_EVD_2, EVSYS_OVR_2 */
    dummyHandler::handler,   /* 39 EVSYS_EVD_3, EVSYS_OVR_3 */
    dummyHandler::handler,   /* 40 EVSYS_EVD_10, EVSYS_EVD_11, EVSYS_EVD_4, EVSYS_EVD_5, EVSYS_EVD_6, EVSYS_EVD_7,
                                  EVSYS_EVD_8, EVSYS_EVD_9, EVSYS_OVR_10, EVSYS_OVR_11, EVSYS_OVR_4, EVSYS_OVR_5,
                                  EVSYS_OVR_6, EVSYS_OVR_7, EVSYS_OVR_8, EVSYS_OVR_9 */
    dummyHandler::handler,       /* 41 Peripheral Access Controller */
    dummyHandler::handler,     /* 42 TAL_BRK */
    dummyHandler::handler,     /* 43 TAL_IPS_0, TAL_IPS_1 */
    (0UL),             /* 44 Reserved */
    dummyHandler::handler,    /* 45 RAM ECC */
    dummyHandler::handler, /* 46 SERCOM0_0 */
    dummyHandler::handler, /* 47 SERCOM0_1 */
    dummyHandler::handler, /* 48 SERCOM0_2 */
    dummyHandler::handler, /* 49 SERCOM0_3, SERCOM0_4, SERCOM0_5, SERCOM0_6 */
    dummyHandler::handler, /* 50 SERCOM1_0 */
    dummyHandler::handler, /* 51 SERCOM1_1 */
    dummyHandler::handler, /* 52 SERCOM1_2 */
    dummyHandler::handler, /* 53 SERCOM1_3, SERCOM1_4, SERCOM1_5, SERCOM1_6 */
    dummyHandler::handler, /* 54 SERCOM2_0 */
    dummyHandler::handler, /* 55 SERCOM2_1 */
    dummyHandler::handler, /* 56 SERCOM2_2 */
    dummyHandler::handler, /* 57 SERCOM2_3, SERCOM2_4, SERCOM2_5, SERCOM2_6 */
    dummyHandler::handler, /* 58 SERCOM3_0 */
    dummyHandler::handler, /* 59 SERCOM3_1 */
    dummyHandler::handler, /* 60 SERCOM3_2 */
    dummyHandler::handler, /* 61 SERCOM3_3, SERCOM3_4, SERCOM3_5, SERCOM3_6 */
#ifdef ID_SERCOM4
    dummyHandler::handler, /* 62 SERCOM4_0 */
    dummyHandler::handler, /* 63 SERCOM4_1 */
    dummyHandler::handler, /* 64 SERCOM4_2 */
    dummyHandler::handler, /* 65 SERCOM4_3, SERCOM4_4, SERCOM4_5, SERCOM4_6 */
#else
    0,
   dummyHandler::handler, //63
    0,
    0,
#endif
#ifdef ID_SERCOM5
    dummyHandler::handler, /* 66 SERCOM5_0 */
    dummyHandler::handler, /* 67 SERCOM5_1 */
    dummyHandler::handler, /* 68 SERCOM5_2 */
    dummyHandler::handler, /* 69 SERCOM5_3, SERCOM5_4, SERCOM5_5, SERCOM5_6 */
#else
   0,
   0,
   0,
   0,
#endif
#ifdef ID_SERCOM6
    dummyHandler::handler, /* 70 SERCOM6_0 */
    dummyHandler::handler, /* 71 SERCOM6_1 */
    dummyHandler::handler, /* 72 SERCOM6_2 */
    dummyHandler::handler, /* 73 SERCOM6_3, SERCOM6_4, SERCOM6_5, SERCOM6_6 */
#else
   0,
   0,
   0,
   0,
#endif
#ifdef ID_SERCOM7
    dummyHandler::handler, /* 74 SERCOM7_0 */
    dummyHandler::handler, /* 75 SERCOM7_1 */
    dummyHandler::handler, /* 76 SERCOM7_2 */
    dummyHandler::handler, /* 77 SERCOM7_3, SERCOM7_4, SERCOM7_5, SERCOM7_6 */
#else
   0,
   0,
   0,
   0,
#endif
#ifdef ID_CAN0
    dummyHandler::handler, /* 78 Control Area Network 0 */
#else
   0,
#endif
#ifdef ID_CAN1
    dummyHandler::handler, /* 79 Control Area Network 1 */
#else
   0,
#endif
#ifdef ID_USB
    dummyHandler::handler, /* 80 USB_EORSM_DNRSM, USB_EORST_RST, USB_LPMSUSP_DDISC, USB_LPM_DCONN, USB_MSOF,
                              USB_RAMACER, USB_RXSTP_TXSTP_0, USB_RXSTP_TXSTP_1, USB_RXSTP_TXSTP_2, USB_RXSTP_TXSTP_3,
                              USB_RXSTP_TXSTP_4, USB_RXSTP_TXSTP_5, USB_RXSTP_TXSTP_6, USB_RXSTP_TXSTP_7,
                              USB_STALL0_STALL_0, USB_STALL0_STALL_1, USB_STALL0_STALL_2, USB_STALL0_STALL_3,
                              USB_STALL0_STALL_4, USB_STALL0_STALL_5, USB_STALL0_STALL_6, USB_STALL0_STALL_7,
                              USB_STALL1_0, USB_STALL1_1, USB_STALL1_2, USB_STALL1_3, USB_STALL1_4, USB_STALL1_5,
                              USB_STALL1_6, USB_STALL1_7, USB_SUSPEND, USB_TRFAIL0_TRFAIL_0, USB_TRFAIL0_TRFAIL_1,
                              USB_TRFAIL0_TRFAIL_2, USB_TRFAIL0_TRFAIL_3, USB_TRFAIL0_TRFAIL_4, USB_TRFAIL0_TRFAIL_5,
                              USB_TRFAIL0_TRFAIL_6, USB_TRFAIL0_TRFAIL_7, USB_TRFAIL1_PERR_0, USB_TRFAIL1_PERR_1,
                              USB_TRFAIL1_PERR_2, USB_TRFAIL1_PERR_3, USB_TRFAIL1_PERR_4, USB_TRFAIL1_PERR_5,
                              USB_TRFAIL1_PERR_6, USB_TRFAIL1_PERR_7, USB_UPRSM, USB_WAKEUP */
    dummyHandler::handler, /* 81 USB_SOF_HSOF */
    dummyHandler::handler, /* 82 USB_TRCPT0_0, USB_TRCPT0_1, USB_TRCPT0_2, USB_TRCPT0_3, USB_TRCPT0_4, USB_TRCPT0_5,
                              USB_TRCPT0_6, USB_TRCPT0_7 */
    dummyHandler::handler, /* 83 USB_TRCPT1_0, USB_TRCPT1_1, USB_TRCPT1_2, USB_TRCPT1_3, USB_TRCPT1_4, USB_TRCPT1_5,
                              USB_TRCPT1_6, USB_TRCPT1_7 */
#else
   0,
   0,
   0,
   0,
#endif
#ifdef ID_GMAC
    dummyHandler::handler, /* 84 Ethernet MAC */
#else
   0,
#endif
    dummyHandler::handler, /* 85 TCC0_CNT_A, TCC0_DFS_A, TCC0_ERR_A, TCC0_FAULT0_A, TCC0_FAULT1_A, TCC0_FAULTA_A,
                               TCC0_FAULTB_A, TCC0_OVF, TCC0_TRG, TCC0_UFS_A */
    dummyHandler::handler, /* 86 TCC0_MC_0 */
    dummyHandler::handler, /* 87 TCC0_MC_1 */
    dummyHandler::handler, /* 88 TCC0_MC_2 */
    dummyHandler::handler, /* 89 TCC0_MC_3 */
    dummyHandler::handler, /* 90 TCC0_MC_4 */
    dummyHandler::handler, /* 91 TCC0_MC_5 */
    dummyHandler::handler, /* 92 TCC1_CNT_A, TCC1_DFS_A, TCC1_ERR_A, TCC1_FAULT0_A, TCC1_FAULT1_A, TCC1_FAULTA_A,
                               TCC1_FAULTB_A, TCC1_OVF, TCC1_TRG, TCC1_UFS_A */
    dummyHandler::handler, /* 93 TCC1_MC_0 */
    dummyHandler::handler, /* 94 TCC1_MC_1 */
    dummyHandler::handler, /* 95 TCC1_MC_2 */
    dummyHandler::handler, /* 96 TCC1_MC_3 */
    dummyHandler::handler, /* 97 TCC2_CNT_A, TCC2_DFS_A, TCC2_ERR_A, TCC2_FAULT0_A, TCC2_FAULT1_A, TCC2_FAULTA_A,
                               TCC2_FAULTB_A, TCC2_OVF, TCC2_TRG, TCC2_UFS_A */
    dummyHandler::handler, /* 98 TCC2_MC_0 */
    dummyHandler::handler, /* 99 TCC2_MC_1 */
    dummyHandler::handler, /* 100 TCC2_MC_2 */
#ifdef ID_TCC3
    TCC3_0::handler, /* 101 TCC3_CNT_A, TCC3_DFS_A, TCC3_ERR_A, TCC3_FAULT0_A, TCC3_FAULT1_A, TCC3_FAULTA_A,
                               TCC3_FAULTB_A, TCC3_OVF, TCC3_TRG, TCC3_UFS_A */
    dummyHandler::handler, /* 102 TCC3_MC_0 */
    dummyHandler::handler, /* 103 TCC3_MC_1 */
#else
   0,
   0,
   0,
#endif
#ifdef ID_TCC4
    dummyHandler::handler, /* 104 TCC4_CNT_A, TCC4_DFS_A, TCC4_ERR_A, TCC4_FAULT0_A, TCC4_FAULT1_A, TCC4_FAULTA_A,
                               TCC4_FAULTB_A, TCC4_OVF, TCC4_TRG, TCC4_UFS_A */
    dummyHandler::handler, /* 105 TCC4_MC_0 */
    dummyHandler::handler, /* 106 TCC4_MC_1 */
#else
   0,
   0,
   0,
#endif
    dummyHandler::handler, /* 107 Basic Timer Counter 0 */
    dummyHandler::handler, /* 108 Basic Timer Counter 1 */
    dummyHandler::handler, /* 109 Basic Timer Counter 2 */
    dummyHandler::handler, /* 110 Basic Timer Counter 3 */
#ifdef ID_TC4
    TC4::handler, /* 111 Basic Timer Counter 4 */
#else
   0,
#endif
#ifdef ID_TC5
    dummyHandler::handler, /* 112 Basic Timer Counter 5 */
#else
   0,
#endif
#ifdef ID_TC6
    dummyHandler::handler, /* 113 Basic Timer Counter 6 */
#else
   0,
#endif
#ifdef ID_TC7
    dummyHandler::handler, /* 114 Basic Timer Counter 7 */
#else
   0,
#endif
    dummyHandler::handler, /* 115 PDEC_DIR_A, PDEC_ERR_A, PDEC_OVF, PDEC_VLC_A */
    dummyHandler::handler, /* 116 PDEC_MC_0 */
    dummyHandler::handler, /* 117 PDEC_MC_1 */
    dummyHandler::handler, /* 118 ADC0_OVERRUN, ADC0_WINMON */
    dummyHandler::handler, /* 119 ADC0_RESRDY */
    dummyHandler::handler, /* 120 ADC1_OVERRUN, ADC1_WINMON */
    dummyHandler::handler, /* 121 ADC1_RESRDY */
    dummyHandler::handler,     /* 122 Analog Comparators */
    dummyHandler::handler,  /* 123 DAC_OVERRUN_A_0, DAC_OVERRUN_A_1, DAC_UNDERRUN_A_0, DAC_UNDERRUN_A_1 */
    dummyHandler::handler,  /* 124 DAC_EMPTY_0 */
    dummyHandler::handler,  /* 125 DAC_EMPTY_1 */
    dummyHandler::handler,  /* 126 DAC_RESRDY_0 */
    dummyHandler::handler,  /* 127 DAC_RESRDY_1 */
#ifdef ID_I2S
    dummyHandler::handler, /* 128 Inter-IC Sound Interface */
#else
   0,
#endif
    dummyHandler::handler,  /* 129 Parallel Capture Controller */
    dummyHandler::handler,  /* 130 Advanced Encryption Standard */
    dummyHandler::handler, /* 131 True Random Generator */
#ifdef ID_ICM
    dummyHandler::handler, /* 132 Integrity Check Monitor */
#else
   0,
#endif
#ifdef ID_PUKCC
    dummyHandler::handler, /* 133 PUblic-Key Cryptography Controller */
#else
   0,
#endif
    dummyHandler::handler, /* 134 Quad SPI interface */
#ifdef ID_SDHC0
    dummyHandler::handler, /* 135 SD/MMC Host Controller 0 */
#else
   0,
#endif
#ifdef ID_SDHC1
    dummyHandler::handler /* 136 SD/MMC Host Controller 1 */
#else
   0,
#endif
  
};

  __weak void  dummyHandler::handler() { while(1) {} }

extern "C" void __cmain( void );
extern "C" __weak void __iar_init_core( void );
extern "C" __weak void __iar_init_vfp( void );

//#pragma required=__vector_table
//void __iar_program_start( void )
//{
//  __iar_init_core();
//  __iar_init_vfp();
//  __cmain();
//}

