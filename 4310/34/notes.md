
# More Authentication Methods

## Verification Code

 - SMS Text
 - Email
 - Authenticator App (or physical device)

### Authenticator Protocol Standard: TOTP

 - Locally generates codes on device; doesn't even
   need network access.
 - Codes are cryptographically generated.
 - Standard, so one app works across many services.

## Passkeys

 - Cryptographic keys are great for authentication.
 - They really are secure.
 - Commonly used for years in SSH authentication.

Two problems:

 - User Experience
 - IT people hate the idea of non-interactive authentication.

Passkeys is a new (~10 year old) standard allows browsers
and mobile app APIs to do cryptographic authetnication
mostly transparently.

Key new trick: Implementations require user presence verificaiton,
by something like fingerprint or face scan.





