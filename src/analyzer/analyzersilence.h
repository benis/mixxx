#ifndef ANALYZER_ANALYZERSILENCE_H
#define ANALYZER_ANALYZERSILENCE_H

#include "analyzer/analyzer.h"
#include "preferences/usersettings.h"

class AnalyzerSilence : public Analyzer {
  public:
    AnalyzerSilence(UserSettingsPointer pConfig);
    virtual ~AnalyzerSilence();

    bool initialize(TrackPointer tio, int sampleRate, int totalSamples) override;
    bool isDisabledOrLoadStoredSuccess(TrackPointer tio) const override;
    void process(const CSAMPLE *pIn, const int iLen) override;
    void finalize(TrackPointer tio) override;
    void cleanup(TrackPointer tio) override;

  private:
    UserSettingsPointer m_pConfig;
    float m_fThreshold;
    int m_iSampleRate;
    int m_iTotalSamples;
    int m_iFramesProcessed;
    bool m_bPrevSilence;
    int m_iSignalBegin;
    int m_iSignalEnd;
};

#endif // ANALYZER_ANALYZERSILENCE_H
