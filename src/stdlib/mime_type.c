/*
 * ================================
 * eli960@qq.com
 * http://www.mailhonor.com/
 * 2017-06-22
 * ================================
 */

#include "zc.h"

const char *zvar_mime_type_application_cotec_stream = "application/octet-stream";
const char *zget_mime_type_from_suffix(const char *suffix, const char *def)
{
    /* {{{ mt_count mt_vector mt_offsets */
    /* auxiliary/mime_type/ */
    static const int mt_count = 538;
    static const char *mt_vector = "%\x00" "application/x-trash\x00" "3gp\x00" "video/3gpp\x00" "7z\x00" "application/x-7z-compressed\x00" "abw\x00" "application/x-abiword\x00" "ai\x00" "application/postscript\x00" "aif\x00" "audio/x-aiff\x00" "aifc\x00" "audio/x-aiff\x00" "aiff\x00" "audio/x-aiff\x00" "alc\x00" "chemical/x-alchemy\x00" "amr\x00" "audio/amr\x00" "anx\x00" "application/annodex\x00" "apk\x00" "application/vnd.android.package-archive\x00" "appcache\x00" "text/cache-manifest\x00" "art\x00" "image/x-jg\x00" "asc\x00" "text/plain\x00" "asf\x00" "video/x-ms-asf\x00" "asn\x00" "chemical/x-ncbi-asn1-spec\x00" "aso\x00" "chemical/x-ncbi-asn1-binary\x00" "asx\x00" "video/x-ms-asf\x00" "atom\x00" "application/atom+xml\x00" "atomcat\x00" "application/atomcat+xml\x00" "atomsrv\x00" "application/atomserv+xml\x00" "au\x00" "audio/basic\x00" "avi\x00" "video/x-msvideo\x00" "awb\x00" "audio/amr-wb\x00" "axa\x00" "audio/annodex\x00" "axv\x00" "video/annodex\x00" "b\x00" "chemical/x-molconn-Z\x00" "bak\x00" "application/x-trash\x00" "bat\x00" "application/x-msdos-program\x00" "bcpio\x00" "application/x-bcpio\x00" "bib\x00" "text/x-bibtex\x00" "bin\x00" "application/octet-stream\x00" "bmp\x00" "image/x-ms-bmp\x00" "boo\x00" "text/x-boo\x00" "book\x00" "application/x-maker\x00" "brf\x00" "text/plain\x00" "bsd\x00" "chemical/x-crossfire\x00" "c\x00" "text/x-csrc\x00" "c++\x00" "text/x-c++src\x00" "c3d\x00" "chemical/x-chem3d\x00" "cab\x00" "application/x-cab\x00" "cac\x00" "chemical/x-cache\x00" "cache\x00" "chemical/x-cache\x00" "cap\x00" "application/vnd.tcpdump.pcap\x00" "cascii\x00" "chemical/x-cactvs-binary\x00" "cat\x00" "application/vnd.ms-pki.seccat\x00" "cbin\x00" "chemical/x-cactvs-binary\x00" "cbr\x00" "application/x-cbr\x00" "cbz\x00" "application/x-cbz\x00" "cc\x00" "text/x-c++src\x00" "cda\x00" "application/x-cdf\x00" "cdf\x00" "application/x-cdf\x00" "cdr\x00" "image/x-coreldraw\x00" "cdt\x00" "image/x-coreldrawtemplate\x00" "cdx\x00" "chemical/x-cdx\x00" "cdy\x00" "application/vnd.cinderella\x00" "cef\x00" "chemical/x-cxf\x00" "cer\x00" "chemical/x-cerius\x00" "chm\x00" "chemical/x-chemdraw\x00" "chrt\x00" "application/x-kchart\x00" "cif\x00" "chemical/x-cif\x00" "class\x00" "application/java-vm\x00" "cls\x00" "text/x-tex\x00" "cmdf\x00" "chemical/x-cmdf\x00" "cml\x00" "chemical/x-cml\x00" "cod\x00" "application/vnd.rim.cod\x00" "com\x00" "application/x-msdos-program\x00" "cpa\x00" "chemical/x-compass\x00" "cpio\x00" "application/x-cpio\x00" "cpp\x00" "text/x-c++src\x00" "cpt\x00" "image/x-corelphotopaint\x00" "cr2\x00" "image/x-canon-cr2\x00" "crl\x00" "application/x-pkcs7-crl\x00" "crt\x00" "application/x-x509-ca-cert\x00" "crw\x00" "image/x-canon-crw\x00" "csd\x00" "audio/csound\x00" "csf\x00" "chemical/x-cache-csf\x00" "csh\x00" "text/x-csh\x00" "csm\x00" "chemical/x-csml\x00" "csml\x00" "chemical/x-csml\x00" "css\x00" "text/css\x00" "csv\x00" "text/csv\x00" "ctab\x00" "chemical/x-cactvs-binary\x00" "ctx\x00" "chemical/x-ctx\x00" "cu\x00" "application/cu-seeme\x00" "cub\x00" "chemical/x-gaussian-cube\x00" "cxf\x00" "chemical/x-cxf\x00" "cxx\x00" "text/x-c++src\x00" "d\x00" "text/x-dsrc\x00" "davmount\x00" "application/davmount+xml\x00" "dcm\x00" "application/dicom\x00" "dcr\x00" "application/x-director\x00" "ddeb\x00" "application/vnd.debian.binary-package\x00" "deb\x00" "application/x-debian-package\x00" "dif\x00" "video/dv\x00" "diff\x00" "text/x-diff\x00" "dir\x00" "application/x-director\x00" "djv\x00" "image/vnd.djvu\x00" "djvu\x00" "image/vnd.djvu\x00" "dl\x00" "video/dl\x00" "dll\x00" "application/x-msdos-program\x00" "dmg\x00" "application/x-apple-diskimage\x00" "dms\x00" "application/x-dms\x00" "doc\x00" "application/msword\x00" "docm\x00" "application/vnd.ms-word.document.macroEnabled.12\x00" "docx\x00" "application/vnd.openxmlformats-officedocument.wordprocessingml.document\x00" "dot\x00" "application/msword\x00" "dotm\x00" "application/vnd.ms-word.template.macroEnabled.12\x00" "dotx\x00" "application/vnd.openxmlformats-officedocument.wordprocessingml.template\x00" "dv\x00" "video/dv\x00" "dvi\x00" "application/x-dvi\x00" "dx\x00" "chemical/x-jcamp-dx\x00" "dxr\x00" "application/x-director\x00" "emb\x00" "chemical/x-embl-dl-nucleotide\x00" "embl\x00" "chemical/x-embl-dl-nucleotide\x00" "eml\x00" "message/rfc822\x00" "ent\x00" "chemical/x-pdb\x00" "eot\x00" "application/vnd.ms-fontobject\x00" "eps\x00" "application/postscript\x00" "eps2\x00" "application/postscript\x00" "eps3\x00" "application/postscript\x00" "epsf\x00" "application/postscript\x00" "epsi\x00" "application/postscript\x00" "erf\x00" "image/x-epson-erf\x00" "es\x00" "application/ecmascript\x00" "etx\x00" "text/x-setext\x00" "exe\x00" "application/x-msdos-program\x00" "ez\x00" "application/andrew-inset\x00" "fb\x00" "application/x-maker\x00" "fbdoc\x00" "application/x-maker\x00" "fch\x00" "chemical/x-gaussian-checkpoint\x00" "fchk\x00" "chemical/x-gaussian-checkpoint\x00" "fig\x00" "application/x-xfig\x00" "flac\x00" "audio/flac\x00" "fli\x00" "video/fli\x00" "flv\x00" "video/x-flv\x00" "fm\x00" "application/x-maker\x00" "frame\x00" "application/x-maker\x00" "frm\x00" "application/x-maker\x00" "gal\x00" "chemical/x-gaussian-log\x00" "gam\x00" "chemical/x-gamess-input\x00" "gamin\x00" "chemical/x-gamess-input\x00" "gan\x00" "application/x-ganttproject\x00" "gau\x00" "chemical/x-gaussian-input\x00" "gcd\x00" "text/x-pcs-gcd\x00" "gcf\x00" "application/x-graphing-calculator\x00" "gcg\x00" "chemical/x-gcg8-sequence\x00" "gen\x00" "chemical/x-genbank\x00" "gf\x00" "application/x-tex-gf\x00" "gif\x00" "image/gif\x00" "gjc\x00" "chemical/x-gaussian-input\x00" "gjf\x00" "chemical/x-gaussian-input\x00" "gl\x00" "video/gl\x00" "gnumeric\x00" "application/x-gnumeric\x00" "gpt\x00" "chemical/x-mopac-graph\x00" "gsf\x00" "application/x-font\x00" "gsm\x00" "audio/x-gsm\x00" "gtar\x00" "application/x-gtar\x00" "gz\x00" "application/gzip\x00" "h\x00" "text/x-chdr\x00" "h++\x00" "text/x-c++hdr\x00" "hdf\x00" "application/x-hdf\x00" "hh\x00" "text/x-c++hdr\x00" "hin\x00" "chemical/x-hin\x00" "hpp\x00" "text/x-c++hdr\x00" "hqx\x00" "application/mac-binhex40\x00" "hs\x00" "text/x-haskell\x00" "hta\x00" "application/hta\x00" "htc\x00" "text/x-component\x00" "htm\x00" "text/html\x00" "html\x00" "text/html\x00" "hwp\x00" "application/x-hwp\x00" "hxx\x00" "text/x-c++hdr\x00" "ica\x00" "application/x-ica\x00" "ice\x00" "x-conference/x-cooltalk\x00" "ico\x00" "image/vnd.microsoft.icon\x00" "ics\x00" "text/calendar\x00" "icz\x00" "text/calendar\x00" "ief\x00" "image/ief\x00" "iges\x00" "model/iges\x00" "igs\x00" "model/iges\x00" "iii\x00" "application/x-iphone\x00" "info\x00" "application/x-info\x00" "inp\x00" "chemical/x-gamess-input\x00" "ins\x00" "application/x-internet-signup\x00" "iso\x00" "application/x-iso9660-image\x00" "isp\x00" "application/x-internet-signup\x00" "ist\x00" "chemical/x-isostar\x00" "istr\x00" "chemical/x-isostar\x00" "jad\x00" "text/vnd.sun.j2me.app-descriptor\x00" "jam\x00" "application/x-jam\x00" "jar\x00" "application/java-archive\x00" "java\x00" "text/x-java\x00" "jdx\x00" "chemical/x-jcamp-dx\x00" "jmz\x00" "application/x-jmol\x00" "jng\x00" "image/x-jng\x00" "jnlp\x00" "application/x-java-jnlp-file\x00" "jp2\x00" "image/jp2\x00" "jpe\x00" "image/jpeg\x00" "jpeg\x00" "image/jpeg\x00" "jpf\x00" "image/jpx\x00" "jpg\x00" "image/jpeg\x00" "jpg2\x00" "image/jp2\x00" "jpm\x00" "image/jpm\x00" "jpx\x00" "image/jpx\x00" "js\x00" "application/javascript\x00" "json\x00" "application/json\x00" "kar\x00" "audio/midi\x00" "key\x00" "application/pgp-keys\x00" "kil\x00" "application/x-killustrator\x00" "kin\x00" "chemical/x-kinemage\x00" "kml\x00" "application/vnd.google-earth.kml+xml\x00" "kmz\x00" "application/vnd.google-earth.kmz\x00" "kpr\x00" "application/x-kpresenter\x00" "kpt\x00" "application/x-kpresenter\x00" "ksp\x00" "application/x-kspread\x00" "kwd\x00" "application/x-kword\x00" "kwt\x00" "application/x-kword\x00" "latex\x00" "application/x-latex\x00" "lha\x00" "application/x-lha\x00" "lhs\x00" "text/x-literate-haskell\x00" "lin\x00" "application/bbolin\x00" "lsf\x00" "video/x-la-asf\x00" "lsx\x00" "video/x-la-asf\x00" "ltx\x00" "text/x-tex\x00" "ly\x00" "text/x-lilypond\x00" "lyx\x00" "application/x-lyx\x00" "lzh\x00" "application/x-lzh\x00" "lzx\x00" "application/x-lzx\x00" "m3g\x00" "application/m3g\x00" "m3u\x00" "audio/x-mpegurl\x00" "m3u8\x00" "application/x-mpegURL\x00" "m4a\x00" "audio/mpeg\x00" "maker\x00" "application/x-maker\x00" "man\x00" "application/x-troff-man\x00" "mbox\x00" "application/mbox\x00" "mcif\x00" "chemical/x-mmcif\x00" "mcm\x00" "chemical/x-macmolecule\x00" "mdb\x00" "application/msaccess\x00" "me\x00" "application/x-troff-me\x00" "mesh\x00" "model/mesh\x00" "mid\x00" "audio/midi\x00" "midi\x00" "audio/midi\x00" "mif\x00" "application/x-mif\x00" "mkv\x00" "video/x-matroska\x00" "mm\x00" "application/x-freemind\x00" "mmd\x00" "chemical/x-macromodel-input\x00" "mmf\x00" "application/vnd.smaf\x00" "mml\x00" "text/mathml\x00" "mmod\x00" "chemical/x-macromodel-input\x00" "mng\x00" "video/x-mng\x00" "moc\x00" "text/x-moc\x00" "mol\x00" "chemical/x-mdl-molfile\x00" "mol2\x00" "chemical/x-mol2\x00" "moo\x00" "chemical/x-mopac-out\x00" "mop\x00" "chemical/x-mopac-input\x00" "mopcrt\x00" "chemical/x-mopac-input\x00" "mov\x00" "video/quicktime\x00" "movie\x00" "video/x-sgi-movie\x00" "mp2\x00" "audio/mpeg\x00" "mp3\x00" "audio/mpeg\x00" "mp4\x00" "video/mp4\x00" "mpc\x00" "chemical/x-mopac-input\x00" "mpe\x00" "video/mpeg\x00" "mpeg\x00" "video/mpeg\x00" "mpega\x00" "audio/mpeg\x00" "mpg\x00" "video/mpeg\x00" "mpga\x00" "audio/mpeg\x00" "mph\x00" "application/x-comsol\x00" "mpv\x00" "video/x-matroska\x00" "ms\x00" "application/x-troff-ms\x00" "msh\x00" "model/mesh\x00" "msi\x00" "application/x-msi\x00" "mvb\x00" "chemical/x-mopac-vib\x00" "mxf\x00" "application/mxf\x00" "mxu\x00" "video/vnd.mpegurl\x00" "nb\x00" "application/mathematica\x00" "nbp\x00" "application/mathematica\x00" "nc\x00" "application/x-netcdf\x00" "nef\x00" "image/x-nikon-nef\x00" "nwc\x00" "application/x-nwc\x00" "o\x00" "application/x-object\x00" "oda\x00" "application/oda\x00" "odb\x00" "application/vnd.oasis.opendocument.database\x00" "odc\x00" "application/vnd.oasis.opendocument.chart\x00" "odf\x00" "application/vnd.oasis.opendocument.formula\x00" "odg\x00" "application/vnd.oasis.opendocument.graphics\x00" "odi\x00" "application/vnd.oasis.opendocument.image\x00" "odm\x00" "application/vnd.oasis.opendocument.text-master\x00" "odp\x00" "application/vnd.oasis.opendocument.presentation\x00" "ods\x00" "application/vnd.oasis.opendocument.spreadsheet\x00" "odt\x00" "application/vnd.oasis.opendocument.text\x00" "oga\x00" "audio/ogg\x00" "ogg\x00" "audio/ogg\x00" "ogv\x00" "video/ogg\x00" "ogx\x00" "application/ogg\x00" "old\x00" "application/x-trash\x00" "one\x00" "application/onenote\x00" "onepkg\x00" "application/onenote\x00" "onetmp\x00" "application/onenote\x00" "onetoc2\x00" "application/onenote\x00" "opf\x00" "application/oebps-package+xml\x00" "opus\x00" "audio/ogg\x00" "orc\x00" "audio/csound\x00" "orf\x00" "image/x-olympus-orf\x00" "otf\x00" "application/font-sfnt\x00" "otg\x00" "application/vnd.oasis.opendocument.graphics-template\x00" "oth\x00" "application/vnd.oasis.opendocument.text-web\x00" "otp\x00" "application/vnd.oasis.opendocument.presentation-template\x00" "ots\x00" "application/vnd.oasis.opendocument.spreadsheet-template\x00" "ott\x00" "application/vnd.oasis.opendocument.text-template\x00" "oza\x00" "application/x-oz-application\x00" "p\x00" "text/x-pascal\x00" "p7r\x00" "application/x-pkcs7-certreqresp\x00" "pac\x00" "application/x-ns-proxy-autoconfig\x00" "pas\x00" "text/x-pascal\x00" "pat\x00" "image/x-coreldrawpattern\x00" "patch\x00" "text/x-diff\x00" "pbm\x00" "image/x-portable-bitmap\x00" "pcap\x00" "application/vnd.tcpdump.pcap\x00" "pcf\x00" "application/x-font-pcf\x00" "pcf.Z\x00" "application/x-font-pcf\x00" "pcx\x00" "image/pcx\x00" "pdb\x00" "chemical/x-pdb\x00" "pdf\x00" "application/pdf\x00" "pfa\x00" "application/x-font\x00" "pfb\x00" "application/x-font\x00" "pfr\x00" "application/font-tdpfr\x00" "pgm\x00" "image/x-portable-graymap\x00" "pgn\x00" "application/x-chess-pgn\x00" "pgp\x00" "application/pgp-encrypted\x00" "pk\x00" "application/x-tex-pk\x00" "pl\x00" "text/x-perl\x00" "pls\x00" "audio/x-scpls\x00" "pm\x00" "text/x-perl\x00" "png\x00" "image/png\x00" "pnm\x00" "image/x-portable-anymap\x00" "pot\x00" "text/plain\x00" "potm\x00" "application/vnd.ms-powerpoint.template.macroEnabled.12\x00" "potx\x00" "application/vnd.openxmlformats-officedocument.presentationml.template\x00" "ppam\x00" "application/vnd.ms-powerpoint.addin.macroEnabled.12\x00" "ppm\x00" "image/x-portable-pixmap\x00" "pps\x00" "application/vnd.ms-powerpoint\x00" "ppsm\x00" "application/vnd.ms-powerpoint.slideshow.macroEnabled.12\x00" "ppsx\x00" "application/vnd.openxmlformats-officedocument.presentationml.slideshow\x00" "ppt\x00" "application/vnd.ms-powerpoint\x00" "pptm\x00" "application/vnd.ms-powerpoint.presentation.macroEnabled.12\x00" "pptx\x00" "application/vnd.openxmlformats-officedocument.presentationml.presentation\x00" "prf\x00" "application/pics-rules\x00" "prt\x00" "chemical/x-ncbi-asn1-ascii\x00" "ps\x00" "application/postscript\x00" "psd\x00" "image/x-photoshop\x00" "py\x00" "text/x-python\x00" "pyc\x00" "application/x-python-code\x00" "pyo\x00" "application/x-python-code\x00" "qgs\x00" "application/x-qgis\x00" "qt\x00" "video/quicktime\x00" "qtl\x00" "application/x-quicktimeplayer\x00" "ra\x00" "audio/x-realaudio\x00" "ram\x00" "audio/x-pn-realaudio\x00" "rar\x00" "application/rar\x00" "ras\x00" "image/x-cmu-raster\x00" "rb\x00" "application/x-ruby\x00" "rd\x00" "chemical/x-mdl-rdfile\x00" "rdf\x00" "application/rdf+xml\x00" "rdp\x00" "application/x-rdp\x00" "rgb\x00" "image/x-rgb\x00" "rm\x00" "audio/x-pn-realaudio\x00" "roff\x00" "application/x-troff\x00" "ros\x00" "chemical/x-rosdal\x00" "rpm\x00" "application/x-redhat-package-manager\x00" "rss\x00" "application/x-rss+xml\x00" "rtf\x00" "application/rtf\x00" "rtx\x00" "text/richtext\x00" "rxn\x00" "chemical/x-mdl-rxnfile\x00" "scala\x00" "text/x-scala\x00" "sce\x00" "application/x-scilab\x00" "sci\x00" "application/x-scilab\x00" "sco\x00" "audio/csound\x00" "scr\x00" "application/x-silverlight\x00" "sct\x00" "text/scriptlet\x00" "sd\x00" "chemical/x-mdl-sdfile\x00" "sd2\x00" "audio/x-sd2\x00" "sda\x00" "application/vnd.stardivision.draw\x00" "sdc\x00" "application/vnd.stardivision.calc\x00" "sdd\x00" "application/vnd.stardivision.impress\x00" "sdf\x00" "chemical/x-mdl-sdfile\x00" "sds\x00" "application/vnd.stardivision.chart\x00" "sdw\x00" "application/vnd.stardivision.writer\x00" "ser\x00" "application/java-serialized-object\x00" "sfd\x00" "application/vnd.font-fontforge-sfd\x00" "sfv\x00" "text/x-sfv\x00" "sgf\x00" "application/x-go-sgf\x00" "sgl\x00" "application/vnd.stardivision.writer-global\x00" "sh\x00" "text/x-sh\x00" "shar\x00" "application/x-shar\x00" "shp\x00" "application/x-qgis\x00" "shtml\x00" "text/html\x00" "shx\x00" "application/x-qgis\x00" "sid\x00" "audio/prs.sid\x00" "sig\x00" "application/pgp-signature\x00" "sik\x00" "application/x-trash\x00" "silo\x00" "model/mesh\x00" "sis\x00" "application/vnd.symbian.install\x00" "sisx\x00" "x-epoc/x-sisx-app\x00" "sit\x00" "application/x-stuffit\x00" "sitx\x00" "application/x-stuffit\x00" "skd\x00" "application/x-koan\x00" "skm\x00" "application/x-koan\x00" "skp\x00" "application/x-koan\x00" "skt\x00" "application/x-koan\x00" "sldm\x00" "application/vnd.ms-powerpoint.slide.macroEnabled.12\x00" "sldx\x00" "application/vnd.openxmlformats-officedocument.presentationml.slide\x00" "smi\x00" "application/smil+xml\x00" "smil\x00" "application/smil+xml\x00" "snd\x00" "audio/basic\x00" "spc\x00" "chemical/x-galactic-spc\x00" "spl\x00" "application/x-futuresplash\x00" "spx\x00" "audio/ogg\x00" "sql\x00" "application/x-sql\x00" "src\x00" "application/x-wais-source\x00" "srt\x00" "text/plain\x00" "stc\x00" "application/vnd.sun.xml.calc.template\x00" "std\x00" "application/vnd.sun.xml.draw.template\x00" "sti\x00" "application/vnd.sun.xml.impress.template\x00" "stl\x00" "application/sla\x00" "stw\x00" "application/vnd.sun.xml.writer.template\x00" "sty\x00" "text/x-tex\x00" "sv4cpio\x00" "application/x-sv4cpio\x00" "sv4crc\x00" "application/x-sv4crc\x00" "svg\x00" "image/svg+xml\x00" "svgz\x00" "image/svg+xml\x00" "sw\x00" "chemical/x-swissprot\x00" "swf\x00" "application/x-shockwave-flash\x00" "swfl\x00" "application/x-shockwave-flash\x00" "sxc\x00" "application/vnd.sun.xml.calc\x00" "sxd\x00" "application/vnd.sun.xml.draw\x00" "sxg\x00" "application/vnd.sun.xml.writer.global\x00" "sxi\x00" "application/vnd.sun.xml.impress\x00" "sxm\x00" "application/vnd.sun.xml.math\x00" "sxw\x00" "application/vnd.sun.xml.writer\x00" "t\x00" "application/x-troff\x00" "tar\x00" "application/x-tar\x00" "taz\x00" "application/x-gtar-compressed\x00" "tcl\x00" "text/x-tcl\x00" "tex\x00" "text/x-tex\x00" "texi\x00" "application/x-texinfo\x00" "texinfo\x00" "application/x-texinfo\x00" "text\x00" "text/plain\x00" "tgf\x00" "chemical/x-mdl-tgf\x00" "tgz\x00" "application/x-gtar-compressed\x00" "thmx\x00" "application/vnd.ms-officetheme\x00" "tif\x00" "image/tiff\x00" "tiff\x00" "image/tiff\x00" "tk\x00" "text/x-tcl\x00" "tm\x00" "text/texmacs\x00" "torrent\x00" "application/x-bittorrent\x00" "tr\x00" "application/x-troff\x00" "ts\x00" "video/MP2T\x00" "tsp\x00" "application/dsptype\x00" "tsv\x00" "text/tab-separated-values\x00" "ttf\x00" "application/font-sfnt\x00" "ttl\x00" "text/turtle\x00" "txt\x00" "text/plain\x00" "udeb\x00" "application/x-debian-package\x00" "uls\x00" "text/iuls\x00" "ustar\x00" "application/x-ustar\x00" "val\x00" "chemical/x-ncbi-asn1-binary\x00" "vcard\x00" "text/vcard\x00" "vcd\x00" "application/x-cdlink\x00" "vcf\x00" "text/vcard\x00" "vcs\x00" "text/x-vcalendar\x00" "vmd\x00" "chemical/x-vmd\x00" "vms\x00" "chemical/x-vamas-iso14976\x00" "vrm\x00" "x-world/x-vrml\x00" "vrml\x00" "x-world/x-vrml\x00" "vsd\x00" "application/vnd.visio\x00" "vss\x00" "application/vnd.visio\x00" "vst\x00" "application/vnd.visio\x00" "vsw\x00" "application/vnd.visio\x00" "wad\x00" "application/x-doom\x00" "wav\x00" "audio/x-wav\x00" "wax\x00" "audio/x-ms-wax\x00" "wbmp\x00" "image/vnd.wap.wbmp\x00" "wbxml\x00" "application/vnd.wap.wbxml\x00" "webm\x00" "video/webm\x00" "wk\x00" "application/x-123\x00" "wm\x00" "video/x-ms-wm\x00" "wma\x00" "audio/x-ms-wma\x00" "wmd\x00" "application/x-ms-wmd\x00" "wml\x00" "text/vnd.wap.wml\x00" "wmlc\x00" "application/vnd.wap.wmlc\x00" "wmls\x00" "text/vnd.wap.wmlscript\x00" "wmlsc\x00" "application/vnd.wap.wmlscriptc\x00" "wmv\x00" "video/x-ms-wmv\x00" "wmx\x00" "video/x-ms-wmx\x00" "wmz\x00" "application/x-ms-wmz\x00" "woff\x00" "application/font-woff\x00" "wp5\x00" "application/vnd.wordperfect5.1\x00" "wpd\x00" "application/vnd.wordperfect\x00" "wrl\x00" "x-world/x-vrml\x00" "wsc\x00" "text/scriptlet\x00" "wvx\x00" "video/x-ms-wvx\x00" "wz\x00" "application/x-wingz\x00" "x3d\x00" "model/x3d+xml\x00" "x3db\x00" "model/x3d+binary\x00" "x3dv\x00" "model/x3d+vrml\x00" "xbm\x00" "image/x-xbitmap\x00" "xcf\x00" "application/x-xcf\x00" "xcos\x00" "application/x-scilab-xcos\x00" "xht\x00" "application/xhtml+xml\x00" "xhtml\x00" "application/xhtml+xml\x00" "xlam\x00" "application/vnd.ms-excel.addin.macroEnabled.12\x00" "xlb\x00" "application/vnd.ms-excel\x00" "xls\x00" "application/vnd.ms-excel\x00" "xlsb\x00" "application/vnd.ms-excel.sheet.binary.macroEnabled.12\x00" "xlsm\x00" "application/vnd.ms-excel.sheet.macroEnabled.12\x00" "xlsx\x00" "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet\x00" "xlt\x00" "application/vnd.ms-excel\x00" "xltm\x00" "application/vnd.ms-excel.template.macroEnabled.12\x00" "xltx\x00" "application/vnd.openxmlformats-officedocument.spreadsheetml.template\x00" "xml\x00" "application/xml\x00" "xpi\x00" "application/x-xpinstall\x00" "xpm\x00" "image/x-xpixmap\x00" "xsd\x00" "application/xml\x00" "xsl\x00" "application/xslt+xml\x00" "xslt\x00" "application/xslt+xml\x00" "xspf\x00" "application/xspf+xml\x00" "xtel\x00" "chemical/x-xtel\x00" "xul\x00" "application/vnd.mozilla.xul+xml\x00" "xwd\x00" "image/x-xwindowdump\x00" "xyz\x00" "chemical/x-xyz\x00" "xz\x00" "application/x-xz\x00" "zip\x00" "application/zip\x00" "zmt\x00" "chemical/x-mopac-input\x00" "~\x00" "application/x-trash\x00" "323\x00" "text/h323\x00";
    static const unsigned short int mt_offsets[] = {0,22,37,68,94,120,137,155,173,196,210,234,278,307,322,337,356,386,418,437,463,495,528,543,563,580,598,616,639,663,695,721,739,768,787,802,827,842,867,881,899,921,943,964,987,1020,1052,1086,1116,1138,1160,1177,1199,1221,1243,1273,1292,1323,1342,1364,1388,1414,1433,1459,1474,1495,1514,1542,1574,1597,1621,1639,1667,1689,1717,1748,1770,1787,1812,1827,1847,1868,1881,1894,1924,1943,1967,1996,2015,2033,2047,2081,2103,2130,2173,2206,2219,2236,2263,2282,2302,2314,2346,2380,2402,2425,2479,2556,2579,2633,2710,2722,2744,2767,2794,2828,2863,2882,2901,2935,2962,2990,3018,3046,3074,3096,3122,3140,3172,3200,3223,3249,3284,3320,3343,3359,3373,3389,3412,3438,3462,3490,3518,3548,3579,3609,3628,3666,3695,3718,3742,3756,3786,3816,3828,3860,3887,3910,3926,3950,3970,3984,4002,4024,4041,4060,4078,4107,4125,4145,4166,4180,4195,4217,4235,4257,4285,4314,4332,4350,4364,4380,4395,4420,4444,4472,4506,4538,4572,4595,4619,4656,4678,4707,4724,4748,4771,4787,4821,4835,4850,4866,4880,4895,4910,4924,4938,4964,4986,5001,5026,5057,5081,5122,5159,5188,5217,5243,5267,5291,5317,5339,5367,5390,5409,5428,5443,5462,5484,5506,5528,5548,5568,5595,5610,5636,5664,5686,5708,5735,5760,5786,5802,5817,5833,5855,5876,5902,5934,5959,5975,6008,6024,6039,6066,6087,6112,6139,6169,6189,6213,6228,6243,6257,6284,6299,6315,6332,6347,6363,6388,6409,6435,6450,6472,6497,6517,6539,6566,6594,6618,6640,6662,6685,6705,6753,6798,6845,6893,6938,6989,7041,7092,7136,7150,7164,7178,7198,7222,7246,7273,7300,7328,7362,7377,7394,7418,7444,7501,7549,7610,7670,7723,7756,7772,7808,7846,7864,7893,7911,7939,7973,8000,8029,8043,8062,8082,8105,8128,8155,8184,8212,8242,8266,8281,8299,8314,8328,8356,8371,8431,8506,8563,8591,8625,8686,8762,8796,8860,8939,8966,8997,9023,9045,9062,9092,9122,9145,9164,9198,9219,9244,9264,9287,9309,9334,9358,9380,9396,9420,9445,9467,9508,9534,9554,9572,9599,9618,9643,9668,9685,9715,9734,9759,9775,9813,9851,9892,9918,9957,9997,10036,10075,10090,10115,10162,10175,10199,10222,10238,10261,10279,10309,10333,10349,10385,10408,10434,10461,10484,10507,10530,10553,10610,10682,10707,10733,10749,10777,10808,10822,10844,10874,10889,10931,10973,11018,11038,11082,11097,11127,11155,11173,11192,11216,11250,11285,11318,11351,11393,11429,11462,11497,11519,11541,11575,11590,11605,11632,11662,11678,11701,11735,11771,11786,11802,11816,11832,11865,11888,11902,11926,11956,11982,11998,12013,12047,12061,12087,12119,12136,12161,12176,12197,12216,12246,12265,12285,12311,12337,12363,12389,12412,12428,12447,12471,12503,12519,12540,12557,12576,12601,12622,12652,12680,12717,12736,12755,12780,12807,12842,12874,12893,12912,12931,12954,12972,12994,13014,13034,13056,13087,13113,13141,13193,13222,13251,13310,13362,13433,13462,13517,13591,13611,13639,13659,13679,13704,13730,13756,13777,13813,13837,13856,13876,13896,13923,13945};
    /* }}} */
    def = (zempty(def)?zvar_mime_type_application_cotec_stream:def);
    unsigned short int start = 0, end = mt_count -1, middle = 0;
    unsigned char sufbuf[32];
    int slen = strlen(suffix);
    if (slen < 1 || slen > 10) {
        return def;
    }
    memcpy(sufbuf, suffix, slen);
    sufbuf[slen] = 0;
    zstr_tolower((char *)sufbuf);

    int sint = sufbuf[0];
    sint = (sint<<8) + sufbuf[1];

    while (start <= end){
        middle = (start + end)/2;
        unsigned char *mmm = (unsigned char *)mt_vector + mt_offsets[middle];
        int mint = mmm[0];
        mint = (mint<<8) + mmm[1];
        int r = 0;
        if (sint == mint) {
            r = strcmp((char *)sufbuf, (char *)mmm);
        } else  if (sint < mint) {
            r = -1;
        } else {
            r = 1;
        }
        if (r == 0) {
            return (char *)mmm + strlen((char *)mmm) + 1;
        } else if (r < 0) {
            end = middle -1;
        } else {
            start = middle + 1;
        }
    }
    return def;
}

const char *zget_mime_type_from_filename(const char *filename, const char *def)
{
    def = (zempty(def)?zvar_mime_type_application_cotec_stream:def);
    const char *p = strrchr(filename, '.');
    if (!p) {
        return def;
    }
    return zget_mime_type_from_suffix(p+1, def);
}

/*
 * Local variables:
 * End:
 * vim600: fdm=marker
 */
