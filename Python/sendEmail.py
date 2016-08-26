import smtplib

#from email.MIMEText import MIMEText
from email.mime.text import MIMEText

def SendMail(Subject, Content, From, To):

    #print 'SendMail', To

    msg = MIMEText(Content,_subtype='html',_charset='gb2312')

    msg['Subject'] = Subject

    msg['From'] = From

    msg['To'] = ', '.join(To)





    #print 'SendMail', To

    server = smtplib.SMTP('localhost')

    #server.set_debuglevel(1)

    server.sendmail(From, To, msg.as_string())

    server.quit()

aMail = '123456789'
MAIL_FROM = 'No-Reply@Sobot.mps.ericsson.com'
MAIL_TO = 'congxv@rayootech.com'

SendMail('Last Sonar Status', aMail, MAIL_FROM, MAIL_TO)