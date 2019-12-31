ManageServerCommHeader::ManageServerReturnCode AVELicenseHost::checkValidPreApprovedRecord(PreApprovedRecord *preApprovedRec)
{	
	if ((preApprovedRec == NULL) || (preApprovedRec->licenseType != sysInfo->getProductType())) {
		return ManageServerCommHeader::STATUS_LICENSE_INVALID_PREAPPROVED_ID;
	}
	/*
	if (sysInfo->is64BitProductType() && !preApprovedRec->allow64Bit) {
		return ManageServerCommHeader::STATUS_LICENSE_PREAPPROVED_32BIT_ONLY;
	}
	*/
	if (preApprovedRec->noLicenseActivated >= preApprovedRec->noLicenseGranted) {
		return ManageServerCommHeader::STATUS_LICENSE_PREAPPROVED_ID_QUOTA;			
	}
	if (SerialGenerator::SerialInfo::canExpired(preApprovedRec->keyExpired)) {
		if (preApprovedRec->keyExpired < CTime::GetCurrentTime()) {
			return ManageServerCommHeader::STATUS_LICENSE_PREAPPROVED_EXPIRED;
		}
	}
	return ManageServerCommHeader::STATUS_OK;
}